#include "my_cv.h"

int main(void)
{
    MyCV my_cv;
    // my_cv.ShowImage0();

    // my_cv.ChangeAndWriteImage0ColorSpaceToGrayHSV();
    // my_cv.Show3Image0();
    // my_cv.CreateGrayImage(66);
    // my_cv.CreateBGRimage(0, 255, 255);
    my_cv.InverseColor(my_cv.image_0, 255);

    return 0;
}