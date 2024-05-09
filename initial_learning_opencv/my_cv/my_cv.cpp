#include "my_cv.h"

MyCV::MyCV()
{
    image_0=cv::imread("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/image_0.jpg");
    if(image_0.empty()==1)
    {
        std::cout << "This image is not found." << std::endl;
    }
}

void MyCV::ChangeAndWriteImage0ColorSpaceToGrayHSV()
{
    cv::cvtColor(image_0, image_0_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(image_0, image_0_hsv, cv::COLOR_BGR2HSV);

    cv::imwrite("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/image_0_gray.png", image_0_gray);
    cv::imwrite("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/image_0_hsv.png", image_0_hsv);
}

void MyCV::ShowImage0()
{
    cv::namedWindow("image_0", cv::WINDOW_NORMAL);
    cv::resizeWindow("image_0", 1200, 800);
    cv::imshow("image_0", image_0);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void MyCV::Show3Image0()
{
    cv::namedWindow("image_0", cv::WINDOW_NORMAL);
    cv::resizeWindow("image_0", 1200, 800);

    cv::namedWindow("image_0_gray", cv::WINDOW_NORMAL);
    cv::resizeWindow("image_0_gray", 1200, 800);

    cv::namedWindow("image_0_hsv", cv::WINDOW_NORMAL);
    cv::resizeWindow("image_0_hsv", 1200, 800);

    cv::imshow("image_0", image_0);
    cv::imshow("image_0_gray", image_0_gray);
    cv::imshow("image_0_hsv", image_0_hsv);

    cv::waitKey(0);
    cv::destroyAllWindows();
}