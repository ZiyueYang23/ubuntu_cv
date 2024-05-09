#include "my_cv.h"

int main(void)
{
    MyCV my_cv;
    // my_cv.ShowImage0();

    my_cv.ChangeAndWriteImage0ColorSpaceToGrayHSV();
    my_cv.Show3Image0();

    return 0;
}