#include "my_cv.h"

int main(void)
{
    MyCV my_cv;
    cv::Mat image_0 = cv::imread("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/Charles Woodbury.jpg");
    cv::Mat image_1 = cv::imread("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/image_0.jpg");
    cv::Mat image_2 = cv::imread("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/BWeLyHqW.jpg");
    cv::Mat image_3 = cv::imread("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/E6C9A85702B42774418C9B7F8FC35635.jpg");
    // my_cv.DispalayAllFunction(image_0);
    // my_cv.TextBitwise();
    // my_cv.TextSplitMergeMixChannels(image_0);
    // my_cv.TextInRang(image_3);
    // my_cv.TextRandomDarwLine();
    // my_cv.TextFillPolyPolylinesDrawContours();
    // my_cv.TextDarwRectangleAndCircle(image_0);
    my_cv.MouseDrawing(image_0);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}