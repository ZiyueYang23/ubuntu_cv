//@ // day_1
// #include <iostream>
// #include <opencv2/opencv.hpp>

// using namespace cv;


// int main(void)
// {
//     Mat src=imread("/home/ziyueyang/Pictures/photograph/paperwall_2.jpg");
//     if(src.empty())
//     {
//         std::cout << "This image is not found." << std::endl;
//     }
//     namedWindow("output", WINDOW_FREERATIO);
//     imshow("output", src);
//     waitKey(0);
//     destroyWindow("output");
// }

//@ //day_2
#include "quickopencv.h"

int main(void)
{
    Mat src = imread("/home/ziyueyang/Pictures/photograph/paperwall_2.jpg");
    // imread B blue G green R rad 取值空间都是0-255 
    // HSV通道 H 0-180,S 0-255, V 0-255
    // H，S是控制颜色 V通道控制亮度 S是控制饱和度
    // 不同色彩通道来调控图片
    namedWindow("normal", WINDOW_FREERATIO);
    imshow("normal", src);

    QuickDemo qd;
    qd.ColorSpaceDemo(src);

    waitKey(0);
    destroyWindow("normal");
}