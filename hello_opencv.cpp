// #include <opencv2/opencv.hpp>
// using namespace cv;
// int main()
// {

//     Mat srcImage = imread("1.jpg");
//     imshow("Origin", srcImage);
//     waitKey(0);
//     return 0;
// }

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat src;

int main(int argc, char **argv)
{
    src = imread("1.jpg"); // 这里是你的图片
    if (src.empty())
    {
        cout << "没有读取到图像" << endl;
        return -1;
    }
    imshow("hello", src);
    waitKey(0);
    return 0;
}