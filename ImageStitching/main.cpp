#include <iostream>
#include "ImageStitching.h"

int main(int argc, char** argv) {
    // Argümanlarýný al
    std::vector<std::string> imagePaths;
    std::string outputPath;

    if (argc < 5) {
        std::cout << "Kullaným: ./image_stitching -i image1.jpg image2.jpg -o output.jpg" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-i" || arg == "--input") {
            // Görüntü dosyalarýný argüman olarak al
            while (i + 1 < argc && argv[i + 1][0] != '-') {
                imagePaths.push_back(argv[i + 1]);
                ++i;
            }
        }
        else if (arg == "-o" || arg == "--output") {
            // Çýktý dosyasýný argüman olarak al
            if (i + 1 < argc) {
                outputPath = argv[i + 1];
                ++i;
            }
        }
    }



    // Görüntüleri yükle
    cv::Mat image2 = cv::imread(imagePaths[0]);
    cv::Mat image1 = cv::imread(imagePaths[1]);

    // ImageStitching nesnesini oluþtur ve iþlemi gerçekleþtir
    ImageStitching* stitcher = new ImageStitching(&image1, &image2);
    stitcher->detectAndExtractFeatures();
    stitcher->matchFeatures();
    cv::Mat homography = stitcher->findHomographyMatrix();
    cv::Mat stitchedImage = stitcher->stitchImages(homography);

    // Panoramik görüntüyü kaydet
    cv::imwrite(outputPath, stitchedImage);
    stitcher->BrightingWithCUDA(stitchedImage.data, stitchedImage.cols, stitchedImage.rows, stitchedImage.channels());

    // Deðerleri artýrýlmýþ görüntüyü kaydet
    cv::imwrite("Cuda_Manuplation.jpg", stitchedImage);

    // ImageStitching nesnesini sil
    delete stitcher;
    return 0;
}