// // @ day_3
// #include <iostream>
// #include <opencv2/opencv.hpp>
// using namespace cv;
// using namespace std;

// int main(void)
// {
//     Mat m1, m2;
//     Mat image = imread("/home/ziyueyang/Pictures/photograph/paperwall_2.jpg");

//     m1 = image.clone();
//     m1.copyTo(m2);

//     // 三通道是BGR,B blue G green R rad 彩色图像
//     Mat m3 = Mat::zeros(Size(8, 8), CV_8UC3);
//     // 0-255 单通道0是黑色255是白色 叫灰度图像
//     // Mat m3 = Mat::zeros(Size(8, 8), CV_8UC1);
//     // 如果直接赋值m3 = 255 让blue拉满就是纯蓝色画面，此时G R通道都是0
//     // m3 = 255;
//     // 这是使用Scalar函数
//     m3 = Scalar(255, 255, 255);
//     cout << m3;
//     namedWindow("m3", WINDOW_FREERATIO);
//     imshow("m3", m3);
//     // 现在又创建了一个m6用另一种方式完成拷贝，此时两m4，m5是黄色，m3,m6是白色
//     Mat m6;
//     m3.copyTo(m6);
//     namedWindow("m6", WINDOW_FREERATIO);
//     imshow("m6", m6);

//     // 注意到此时m4=m3直接进行赋值，然后我再show m3，结果是m3被改变了
//     // 也就是说如果直接用m4=m3，就类似于引用，起个别名，始终指向这一块内存。
//     Mat m4 = m3;
//     m4 = Scalar(0, 255, 255);
//     namedWindow("m4", WINDOW_FREERATIO);
//     imshow("m4", m3);

//     // 此时m3已经被修改了，因此结果就是两个黄色图片和最原来m3的白色图片。
//     Mat m5 = m3.clone();
//     namedWindow("m5", WINDOW_FREERATIO);
//     imshow("m5", m5);

//     waitKey(0);
//     destroyAllWindows();

//     return 0;
// }

// @ day_4
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(void)
{
    Mat image = imread("/home/ziyueyang/Pictures/photograph/paperwall_2.jpg");
    Mat m0 = image.clone();
    int rows = image.rows;
    int cols = image.cols;
    int channels = image.channels();
    // 反色
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (channels == 1)
            {
                // 灰度空间
                int pv = image.at<uchar>(row, col);
                image.at<uchar>(row, col) = 255 - pv;
            }
            if (channels == 3)
            {
                // 彩色空间
                Vec3b bgr = image.at<Vec3b>(row, col);
                image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
                image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
                image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
            }
        }
    }
    namedWindow("image", WINDOW_FREERATIO);
    imshow("image", image);
    namedWindow("m0", WINDOW_FREERATIO);
    imshow("m0", m0);
    waitKey(0);
    destroyAllWindows();

    return 0;
}