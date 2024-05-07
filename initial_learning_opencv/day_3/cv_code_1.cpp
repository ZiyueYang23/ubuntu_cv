#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
    Mat m1, m2;
    Mat image = imread("/home/ziyueyang/Pictures/photograph/paperwall_2.jpg");

    m1 = image.clone();
    m1.copyTo(m2);

    Mat m3 = Mat::zeros(Size(8, 8), CV_8UC1);
    // 0-255 单通道0是黑色255是白色
    // Mat m3 = Mat::zeros(Size(8, 8), CV_8UC1);
    cout << m3;
    m3 = 255;
    namedWindow("8*8 zeros", WINDOW_FREERATIO);
    imshow("8*8 zeros", m3);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
