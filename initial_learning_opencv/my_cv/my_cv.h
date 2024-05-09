#ifndef _MY_CV_H_
#define _MY_CV_H_

#include <iostream>
#include <opencv2/opencv.hpp>

class MyCV
{
public:
    cv::Mat image_0;
    cv::Mat image_0_gray;
    cv::Mat image_0_hsv;

public:
    // 构造函数默认读取一张图片到image_0
    MyCV();

    // 色彩空间转换
    void ChangeAndWriteImage0ColorSpaceToGrayHSV();

    // show image_0 
    void ShowImage0();
    // show image_0,image_0_gray and image_0_hsv 
    void Show3Image0();
};

#endif