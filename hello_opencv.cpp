#include "opencv2/opencv.hpp"
#include <Windows.h> // 引入 Windows 头文件
#pragma comment(lib, "user32.lib")
#include <iostream>


void showMat(cv::Mat image)
{
    cv::namedWindow("image", cv::WINDOW_NORMAL); // 设置窗口属性为可调整大小

    // 获取屏幕尺寸
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);

    // 计算最大显示尺寸
    int max_size = std::min(screen_width, screen_height) * 0.8; // 取屏幕尺寸的 80%
    double scale = std::min(1.0, std::min(1.0 * max_size / image.cols, 1.0 * max_size / image.rows)); // 计算缩放比例

    cv::Mat display_image;
    cv::resize(image, display_image, cv::Size(), scale, scale); // 缩小图像
    cv::imshow("image", display_image); // 显示图像
    cv::resizeWindow("image", display_image.cols, display_image.rows); // 调整窗口大小为图像大小
    cv::waitKey(0); // 等待按键
}

int main(int argc, char const *argv[])
{
	cv::Mat img = cv::imread("D:\\photograph\\kOJZ5ofe.jpg");
	if (img.empty())
		std::cout << "image is empty or the path is invalid!" << std::endl;
    showMat(img);
    return 0;
}