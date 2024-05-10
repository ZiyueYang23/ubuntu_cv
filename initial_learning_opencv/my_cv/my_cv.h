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

    // change image_0 color space to gray and hsv,and write in photo_gallery
    void ChangeAndWriteImage0ColorSpaceToGrayHSV();

    // show image_0 
    void ShowImage0();

    // show image
    void Show(const cv::Mat &image,const char *name="image");
    
    // show image_0,image_0_gray and image_0_hsv
    void Show3Image0();

    // create gray image and show this image but no storage
    cv::Mat CreateGrayImage(int degree);

    // create BGR image and show this image but no storage
    cv::Mat CreateBGRimage(int blue, int green, int rad);

    // inverse color degree-bgr[0..]
    cv::Mat InverseColor(cv::Mat &image ,int degree);
};

#endif