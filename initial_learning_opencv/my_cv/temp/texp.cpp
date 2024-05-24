#include <opencv2/opencv.hpp>
#include <iostream>

cv::Point sp(-1, -1);
cv::Point ep(-1, -1);
cv::Mat temp;

void OnDraw(int event, int x, int y, int flags, void *userdata)
{
    cv::Mat &image = *((cv::Mat *)userdata);

    if (event == cv::EVENT_LBUTTONDOWN)
    {
        sp.x = x;
        sp.y = y;
        std::cout << "start point :" << sp << std::endl;
    }
    else if (event == cv::EVENT_LBUTTONUP)
    {
        ep.x = x;
        ep.y = y;
        int dx = std::abs(ep.x - sp.x);
        int dy = std::abs(ep.y - sp.y);
        if (dx > 0 && dy > 0)
        {
            cv::Rect box(sp.x, sp.y, dx, dy);
            cv::rectangle(image, box, cv::Scalar(0, 0, 255), 4, cv::LINE_AA);
            cv::imshow("mouse drawing", image);
        }
            sp.x = -1;
            sp.y = -1;
    }
    else if (event == cv::EVENT_MOUSEMOVE)
    {
        if (sp.x >= 0 && sp.y >= 0)
        {
            ep.x = x;
            ep.y = y;
                temp.copyTo(image); // Restore the original image
            int dx = std::abs(ep.x - sp.x);
            int dy = std::abs(ep.y - sp.y);
            if (dx > 0 && dy > 0)
            {
                cv::Rect box(sp.x, sp.y, dx, dy);
                cv::rectangle(image, box, cv::Scalar(0, 0, 255), 4, cv::LINE_AA);
                cv::imshow("mouse drawing", image);
            }
        }
    }
}

void MouseDrawing(cv::Mat &image)
{
    cv::namedWindow("mouse drawing", cv::WINDOW_NORMAL);
    cv::resizeWindow("mouse drawing", 1200, 800);
    cv::setMouseCallback("mouse drawing", OnDraw, (void *)&image);
    cv::imshow("mouse drawing", image);
    temp = image.clone(); // Clone the image for temporary drawing
}

int main()
{
    cv::Mat image = cv::Mat::zeros(800, 1200, CV_8UC3);
    MouseDrawing(image);
    cv::waitKey(0);
    return 0;
}