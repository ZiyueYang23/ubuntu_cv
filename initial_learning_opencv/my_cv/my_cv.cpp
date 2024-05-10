#include "my_cv.h"

MyCV::MyCV()
{
    image_0 = cv::imread("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/image_0.jpg");
    if (image_0.empty() == 1)
    {
        std::cout << "This image is not found." << std::endl;
    }
}

void MyCV::ChangeAndWriteImage0ColorSpaceToGrayHSV()
{
    // src source 源，dst destination 目标
    cv::cvtColor(image_0, image_0_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(image_0, image_0_hsv, cv::COLOR_BGR2HSV);

    cv::imwrite("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/image_0_gray.png", image_0_gray);
    cv::imwrite("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/image_0_hsv.png", image_0_hsv);
}

void MyCV::Show(const cv::Mat &image, const char *name) 
{
    cv::namedWindow(name, cv::WINDOW_NORMAL);
    cv::resizeWindow(name, 1200, 800);
    cv::imshow(name, image);

    cv::waitKey(0);
    cv::destroyAllWindows();
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

cv::Mat MyCV::CreateGrayImage(int degree)
{
    // zeros 是矩阵全初始化为0 ，可以直接1200,800,CV_8UC1 用cv::Size()是代码更加清晰易读
    // 8u每一个像素由8位无符号整数一字节表示2^8 256 0-255
    // C1就是通道数为一即 灰度图像
    cv::Mat gray_image = cv::Mat::zeros(cv::Size(1200, 800), CV_8UC1);
    gray_image = degree;
    cv::Mat text_copyto_image;
    // 两种复制方式之一
    gray_image.copyTo(text_copyto_image);
    Show(text_copyto_image);

    return gray_image;
}

cv::Mat MyCV::CreateBGRimage(int blue, int green, int rad)
{
    // 创建全1矩阵，8位无符号整数3通道
    cv::Mat bgr_image = cv::Mat::ones(cv::Size(1200, 800), CV_8UC3);
    bgr_image = cv::Scalar(blue, green, rad);
    // 另外一种复制方式
    cv::Mat text_clone_image = bgr_image.clone();
    Show(text_clone_image);

    return bgr_image;
}

cv::Mat MyCV::InverseColor(cv::Mat &image, int degree)
{
    Show(image);

    int rows = image.rows;
    int cols = image.cols;
    int channels = image.channels();

    for (int row(0); row < rows; row++)
    {
        for (int col(0); col < cols; col++)
        {
            if (channels == 1)
            {
                // gray
                // 读取该图片在row col处的像素点的数值，此时是灰度图像就是单通道
                int point_color = image.at<uchar>(row, col);
                // 反色255-原来的数值 就完成反色
                image.at<uchar>(row, col) = degree - point_color;
            }

            if (channels == 3)
            {
                // BGR
                // 三通道同理，只不过就是注意用下标表示区分通道
                cv::Vec3b point_color = image.at<cv::Vec3b>(row, col);
                image.at<cv::Vec3b>(row, col)[0] = degree - point_color[0];
                image.at<cv::Vec3b>(row, col)[1] = degree - point_color[1];
                image.at<cv::Vec3b>(row, col)[2] = degree - point_color[2];
            }
        }
    }
    Show(image);

    return image;
}