#ifndef IMAGE_STITCHING_H
#define IMAGE_STITCHING_H

#include <iostream>
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/opencv.hpp"

class ImageStitching {
public:
    ImageStitching(cv::Mat* image1, cv::Mat* image2);
    ~ImageStitching();

    void detectAndExtractFeatures();
    void matchFeatures();
    cv::Mat findHomographyMatrix();
    cv::Mat stitchImages(const cv::Mat& homography);
    void BrightingWithCUDA(unsigned char* Input_Image, int Height, int Width, int Channels);

private:
    cv::Ptr<cv::FeatureDetector> detector;
    cv::Ptr<cv::DescriptorExtractor> extractor;
    cv::Ptr<cv::DescriptorMatcher> matcher;

    cv::Mat* image1;
    cv::Mat* image2;
    cv::KeyPoint keypoints1;
    cv::KeyPoint keypoints2;
    cv::Mat descriptors1;
    cv::Mat descriptors2;
    std::vector<cv::DMatch> matches;
    const float ratioThresh = 0.74f;
};

#endif // IMAGE_STITCHING_H