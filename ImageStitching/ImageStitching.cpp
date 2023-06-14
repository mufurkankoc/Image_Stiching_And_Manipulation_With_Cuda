#include "ImageStitching.h"
#include <opencv2/xfeatures2d.hpp>

ImageStitching::ImageStitching(cv::Mat* image1, cv::Mat* image2)
    : image1(image1), image2(image2) {
    // Constructor oluþtur
    detector = cv::ORB::create();
    extractor = cv::ORB::create();
    matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::BRUTEFORCE);
}

ImageStitching::~ImageStitching() {
    // Bellek sýzýntýsýný önlemek için pointerlarý sil
    delete detector;
    delete extractor;
    delete matcher;
}

void ImageStitching::detectAndExtractFeatures() {
    // Görüntülerden özellik çýkarýmý yap
    detector->detect(*image1, keypoints1);
    detector->detect(*image2, keypoints2);

    extractor->compute(*image1, keypoints1, descriptors1);
    extractor->compute(*image2, keypoints2, descriptors2);
}

void ImageStitching::matchFeatures() {
    // Eþleþtirmeleri bul
    std::vector<std::vector<cv::DMatch>> knnMatches;
    matcher->knnMatch(descriptors1, descriptors2, knnMatches, 2);

    for (const auto& match : knnMatches) {
        if (match.size() >= 2 && match[0].distance < ratioThresh * match[1].distance) {
            matches.push_back(match[0]);
        }
    }
}

cv::Mat ImageStitching::findHomographyMatrix() {
    // Homografi matris hesapla
    std::vector<cv::Point2f> points1, points2;
    for (const cv::DMatch& match : matches) {
        points1.push_back(keypoints1[match.queryIdx].pt);
        points2.push_back(keypoints2[match.trainIdx].pt);
    }

    return cv::findHomography(points1, points2, cv::RANSAC);
}

cv::Mat ImageStitching::stitchImages(const cv::Mat& homography) {
    // Warping ve birleþtirme iþlemi yap
    cv::Mat warpedImage1;
    cv::warpPerspective(*image1, warpedImage1, homography, cv::Size(image1->cols + image2->cols, image1->rows));

    cv::Mat stitchedImage = warpedImage1.clone();
    cv::Mat roi(stitchedImage, cv::Rect(0, 0, image2->cols, image2->rows));
    image2->copyTo(roi);

    return stitchedImage;
}

