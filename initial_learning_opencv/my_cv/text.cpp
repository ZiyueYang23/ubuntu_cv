#include "my_cv.h"

int main(void)
{
    MyCV my_cv;
    cv::Mat image_0 = cv::imread("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/Charles Woodbury.jpg");
    cv::Mat image_1 = cv::imread("/home/ziyueyang/ubuntu_code/ubuntu_cv/photo_gallery/image_0.jpg");

    my_cv.ChangeToGrayHSVAndSoOnByWaitKey(image_1);

    // cv::waitKey(0);
    // cv::destroyAllWindows();
    return 0;
}