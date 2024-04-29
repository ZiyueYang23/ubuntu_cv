#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat src = imread("/home/ziyueyang/Pictures/photograph/paperwall_2.jpg", IMREAD_ANYCOLOR); // 这里是你的图片
    if (src.empty())
    {
        cout << "没有读取到图像" << endl;
        return -1;
    }
    namedWindow("output", WINDOW_FREERATIO);
    imshow("output", src);
    waitKey(0);
    destroyWindow("output");
    return 0;
}