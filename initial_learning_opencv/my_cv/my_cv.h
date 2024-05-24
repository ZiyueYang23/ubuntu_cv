#ifndef _MY_CV_H_
#define _MY_CV_H_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <cmath>
class MyCV
{
public:
    cv::Mat image_0;
    cv::Mat image_0_gray;
    cv::Mat image_0_hsv;

    // 用于鼠标框图时
    // cv::Point start_point;
    // cv::Point end_point;
    // cv::Mat temp;
    // static MyCV *instance
public:
    // defult read image_0 in class.
    MyCV();

    // change image_0 color space to gray and hsv,and write in photo_gallery
    void ChangeAndWriteImage0ColorSpaceToGrayHSV();
    // show image_0
    void ShowImage0();
    // show image_0,image_0_gray and image_0_hsv
    void Show3Image0();

    // show image 1,2,3
    void Show(const cv::Mat &image, const char *name = "image");
    void Show(const cv::Mat &image_1, const cv::Mat &image_2, const char *name_1 = "image_1", const char *name_2 = "image_2");
    void Show(const cv::Mat &image_1, const cv::Mat &image_2, const cv::Mat &image_3, const char *name_1, const char *name_2, const char *name_3);

    // create gray image and show this image but no storage
    cv::Mat CreateGrayImage(int degree);
    // create BGR image and show this image but no storage
    cv::Mat CreateBGRimage(int blue, int green, int rad);

    // inverse color degree-bgr[0..]
    cv::Mat InverseColor(cv::Mat &image, int degree = 255);

    // add 3 channels color b g r
    cv::Mat Add3PointColor(cv::Mat &image, int b = 50, int g = 50, int r = 50);
    // subtract 3 channels color b g r
    cv::Mat Subtract3PointColor(cv::Mat &image, int b = 50, int g = 50, int r = 50);
    // mutliply 3 channels color b g r
    cv::Mat Mutliply3PointColor(cv::Mat &image, int b = 2, int g = 2, int r = 2);
    // divide 3 channels color b g r
    cv::Mat Divide3PointColor(cv::Mat &image, int b = 2, int g = 2, int r = 2);

    // change brightness and contrast by trackbar
    void ChangeBrightnessConstrastByTrackbar(cv::Mat &image);

    // with menu you can choose different function ,all by myself ,you can try keyboard enter 1,2,3,4,5,0,+,-,*,/ ,that is fun,have a good time hh..
    cv::Mat DispalayAllFunction(cv::Mat &image);

    // show different color style by applyColorMap with COLORMAP_...
    void ShowDiffColorStyle(cv::Mat &image);

    // get one image min max value and location,also get mean and stddev
    void GetMinMaxLocAndMeanStddev(cv::Mat &image);

    // show Bitwise_and or not xor ,create rectangle and use bitWise_and or not...
    void TextBitwise();
    // text split merge mixChannels functions
    void TextSplitMergeMixChannels(cv::Mat &image);
    // text inRang
    void TextInRang(cv::Mat &image);
    // text darw rectangle circle...
    void TextDarwRectangleAndCircle(cv::Mat &image);
    // text random draw line
    void TextRandomDrawLine();
    // text functions fillPoly polylines drawContours...
    void TextFillPolyPolylinesDrawContours();

    void MouseDrawing(cv::Mat &image);

private:
    // default size is 1200 800 and flag is WINDOW_NORMAL
    void NamedAndResizeWindow(const char *winname);
    // menu
    void PrintMenu();

    // Trackbar call back
    // brightness
    static void ChangeBrightness(int b, void *userdata);
    // contrast
    static void ChangeContrast(int b, void *userdata);
    // mouse
    static void OnDraw(int event, int x, int y, int flages, void *userdata);
};

#endif