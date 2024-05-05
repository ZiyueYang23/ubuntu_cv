#include "quickopencv.h"

void QuickDemo::ColorSpaceDemo(Mat &image)
{
    Mat gray;
    Mat hsv;
    cvtColor(image, hsv, COLOR_BGR2HSV);
    cvtColor(image, gray, COLOR_BGR2GRAY);
    namedWindow("HSV", WINDOW_FREERATIO);
    imshow("HSV", hsv);
    namedWindow("灰度", WINDOW_FREERATIO);
    imshow("灰度", gray);
    imwrite("/home/ziyueyang/ubuntu_cv/photo_gallery/hsv_0.jpg", hsv);
    imwrite("/photo_gallery/gray.jpg", gray);
}