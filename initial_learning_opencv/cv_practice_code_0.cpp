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
    namedWindow("normal", WINDOW_FREERATIO);
    imshow("normal", src);

    QuickDemo qd;
    qd.ColorSpaceDemo(src);

    waitKey(0);
    destroyWindow("normal");
}