#include "my_cv.h"
// @ public
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
void MyCV::Show(const cv::Mat &image_1, const cv::Mat &image_2, const char *name_1, const char *name_2)
{
    cv::namedWindow(name_1, cv::WINDOW_NORMAL);
    cv::resizeWindow(name_1, cv::Size(1200, 800));

    cv::namedWindow(name_2, cv::WINDOW_NORMAL);
    cv::resizeWindow(name_2, cv::Size(1200, 800));

    cv::imshow(name_1, image_1);
    cv::imshow(name_2, image_2);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void MyCV::Show(const cv::Mat &image_1, const cv::Mat &image_2, const cv::Mat &image_3, const char *name_1 = "image_1", const char *name_2 = "image_2", const char *name_3 = "image_3")
{
    cv::namedWindow(name_1, cv::WINDOW_NORMAL);
    cv::resizeWindow(name_1, cv::Size(1200, 800));

    cv::namedWindow(name_2, cv::WINDOW_NORMAL);
    cv::resizeWindow(name_2, cv::Size(1200, 800));

    cv::namedWindow(name_3, cv::WINDOW_NORMAL);
    cv::resizeWindow(name_3, cv::Size(1200, 800));
    cv::imshow(name_1, image_1);
    cv::imshow(name_2, image_2);
    cv::imshow(name_3, image_3);

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

cv::Mat MyCV::CreateBGRimage(int blue, int green, int red)
{
    // 创建全1矩阵，8位无符号整数3通道
    cv::Mat bgr_image = cv::Mat::ones(cv::Size(1200, 800), CV_8UC3);
    bgr_image = cv::Scalar(blue, green, red);
    // 另外一种复制方式
    cv::Mat text_clone_image = bgr_image.clone();
    Show(text_clone_image);

    return bgr_image;
}

cv::Mat MyCV::InverseColor(cv::Mat &image, int degree)
{
    // Show(image);
    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
    int rows = image.rows;
    int cols = image.cols;
    int channels = image.channels();

    // @ 暴力方式
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
                dst.at<uchar>(row, col) = degree - point_color;
            }

            if (channels == 3)
            {
                // BGR
                // 三通道同理，只不过就是注意用下标表示区分通道
                cv::Vec3b point_color = image.at<cv::Vec3b>(row, col);
                dst.at<cv::Vec3b>(row, col)[0] = degree - point_color[0];
                dst.at<cv::Vec3b>(row, col)[1] = degree - point_color[1];
                dst.at<cv::Vec3b>(row, col)[2] = degree - point_color[2];
            }
        }
    }

    // // @ 用指针比暴力for循环效率稍微要高一点
    // // 后续细细体会
    // for (int row(0); row < rows; row++)
    // {
    //     uchar *current_row = image.ptr<uchar>(row);
    //     for (int col(0); col < cols; col++)
    //     {
    //         if (channels == 1)
    //         {
    //             // gray
    //             int point_color = *current_row;
    //             *current_row++ = degree - point_color;
    //         }

    //         if (channels == 3)
    //         {
    //             // BGR
    //             *current_row++ = degree - *current_row;
    //             *current_row++ = degree - *current_row;
    //             *current_row++ = degree - *current_row;
    //         }
    //     }
    // }

    return dst;
}

cv::Mat MyCV::Add3PointColor(cv::Mat &image, int b, int g, int r)
{
    cv::Mat temp = cv::Mat::zeros(image.size(), image.type());
    // 用scalar赋值
    temp = cv::Scalar(b, g, r);
    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
    // 就这里需要注意参数的位置，第一个是image,第二个是temp,第三个是dst是结果
    cv::add(image, temp, dst);
    // Show(image, dst, "image", "dst");
    return dst;
}

cv::Mat MyCV::Subtract3PointColor(cv::Mat &image, int b, int g, int r)
{
    cv::Mat temp = cv::Mat::zeros(image.size(), image.type());
    temp = cv::Scalar(b, g, r);
    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
    cv::subtract(image, temp, dst);
    // Show(image, dst, "image", "dst");
    return dst;
}

cv::Mat MyCV::Mutliply3PointColor(cv::Mat &image, int b, int g, int r)
{
    cv::Mat temp = cv::Mat::zeros(image.size(), image.type());
    temp = cv::Scalar(b, g, r);
    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
    cv::multiply(image, temp, dst);
    // Show(image, dst, "image", "dst");
    return dst;
}

cv::Mat MyCV::Divide3PointColor(cv::Mat &image, int b, int g, int r)
{
    cv::Mat temp = cv::Mat::zeros(image.size(), image.type());
    temp = cv::Scalar(b, g, r);
    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
    cv::divide(image, temp, dst);
    // Show(image, dst, "image", "dst");
    return dst;
}

void MyCV::ChangeBrightnessConstrastByTrackbar(cv::Mat &image)
{
    // 命名一个窗口
    cv::namedWindow("image_", cv::WINDOW_NORMAL);
    // 设置默认大小
    cv::resizeWindow("image_", 1200, 800);
    // 默认亮度
    int brightness = 50;
    // 默认对比度
    int contrast = 100;
    // 最大亮度
    int max_brightness = 100;
    // 最大对比度
    int max_contrast = 500;
    // 创建滑动条，第一个参数是亮度，第二个是窗口名称，第三个参数是亮度，是指针动态改值的目的，第四个参数是最大亮度
    // 第五个参数是一个函数指针，叫回调函数，是我们实现改值的重点，就是在回调函数里面完成改值，第六个参数就是要动的图片
    cv::createTrackbar("brightness", "image_", &brightness, max_brightness, ChangeBrightness, (void *)&image);
    // 第六个参数是void*指针，传进去要强转成void*
    cv::createTrackbar("contrast", "image_", &contrast, max_contrast, ChangeContrast, (void *)&image);

    // 循环标志位
    bool is_running = true;
    while (is_running)
    {
        // 这里1是1毫秒，如果用户有输入则返回到key里面，并且是尽快（1毫秒）返回到key
        // 然后再进行判断如果是27 对应键盘的Ese键，改值结束循环。
        int key = cv::waitKey(1);
        if (key == 27)
        {
            is_running = false;
        }
    }
    // 销毁所有窗口
    cv::destroyAllWindows();
}

cv::Mat MyCV::DispalayAllFunction(cv::Mat &image)
{
    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
    bool is_running = true;
    PrintMenu();
    while (is_running)
    {
        int key = cv::waitKey(1);
        switch (key)
        {
        case 27:
            is_running = false;
            break;
        case '0':
            image.copyTo(dst);
            std::cout << "come back to initial image!" << std::endl;
            break;
        case '1':
            cv::cvtColor(image, dst, cv::COLOR_BGR2GRAY);
            std::cout << "image change to gray!" << std::endl;
            break;
        case '2':
            cv::cvtColor(image, dst, cv::COLOR_BGR2HSV);
            std::cout << "image change to HSV!" << std::endl;
            break;
        case '3':
            InverseColor(image).copyTo(dst);
            std::cout << "image inverse color!" << std::endl;
            break;
        case '+':
            Add3PointColor(image).copyTo(dst);
            std::cout << "image brightness add 50!" << std::endl;
            break;
        case '-':
            Subtract3PointColor(image).copyTo(dst);
            std::cout << "image brightness subtract 50!" << std::endl;
            break;
        case '*':
            Mutliply3PointColor(image).copyTo(dst);
            std::cout << "image brightness mutliply 5!" << std::endl;
            break;
        case '/':
            Divide3PointColor(image).copyTo(dst);
            std::cout << "image brightness divide 5!" << std::endl;
            break;
        case '4':
            ChangeBrightnessConstrastByTrackbar(image);
            break;
        case '5':
            ShowDiffColorStyle(image);
        default:
            break;
        }
        NamedAndResizeWindow("image");
        NamedAndResizeWindow("dst");
        cv::imshow("image", image);
        cv::imshow("dst", dst);
    }
    cv::destroyAllWindows();
    return dst;
}

void MyCV::ShowDiffColorStyle(cv::Mat &image)
{
    int color_style_map[] =
        {
            cv::COLORMAP_AUTUMN,
            cv::COLORMAP_BONE,
            cv::COLORMAP_CIVIDIS,
            cv::COLORMAP_COOL,
            cv::COLORMAP_DEEPGREEN,
            cv::COLORMAP_HOT,
            cv::COLORMAP_HSV,
            cv::COLORMAP_INFERNO,
            cv::COLORMAP_JET,
            cv::COLORMAP_MAGMA,
            cv::COLORMAP_OCEAN,
            cv::COLORMAP_PARULA,
            cv::COLORMAP_PINK,
            cv::COLORMAP_PLASMA,
            cv::COLORMAP_RAINBOW,
            cv::COLORMAP_SPRING,
            cv::COLORMAP_SUMMER,
            cv::COLORMAP_TURBO,
            cv::COLORMAP_TWILIGHT,
            cv::COLORMAP_VIRIDIS,
            cv::COLORMAP_WINTER,
        };

    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
    int index(0);
    bool is_running = true;
    while (is_running)
    {
        int c = cv::waitKey(500);
        if (c == 27)
        {
            is_running = false;
            break;
        }
        cv::applyColorMap(image, dst, color_style_map[index % 21]);
        index++;
        NamedAndResizeWindow("image");
        NamedAndResizeWindow("dst");
        cv::imshow("image", image);
        cv::imshow("dst", dst);
    }
}

void MyCV::TextBitwise()
{
    cv::Mat m1 = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
    cv::Mat m2 = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
    // 创建矩形，Rect中前两个参数就是矩形左上角顶点的坐标，后两个就是长宽
    // Scalar很熟了就是给颜色，第四个参数是边框厚度如果想填充就-1,正数就是表示边框的宽度，第五个参数一般LINE_8,第六个是小数点，笔记中有详解
    cv::rectangle(m1, cv::Rect(100, 100, 80, 80), cv::Scalar(255, 0, 255), -1, cv::LINE_8, 0);
    cv::rectangle(m2, cv::Rect(150, 150, 80, 80), cv::Scalar(0, 255, 255), -1, cv::LINE_8, 0);
    cv::Mat dst = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
    cv::bitwise_or(m1, m2, dst);
    Show(m1, m2, dst, "m1", "m2", "or->dst");
    cv::bitwise_xor(m1, m2, dst);
    Show(dst, "xor->dst");
    cv::bitwise_and(m1, m2, dst);
    Show(dst, "and->dst");
    cv::bitwise_not(m1, dst);
    Show(dst, "notm1->dst");
}

void MyCV::TextSplitMergeMixChannels(cv::Mat &image)
{
    std::vector<cv::Mat> mat_vertor;
    cv::split(image, mat_vertor);
    Show(mat_vertor[0], mat_vertor[1], mat_vertor[2], "blue channel", "green channel", "red channel");
    // 如何理解上述操作，现在仅仅是分别取到了三通道的每一个通道的单通道值。
    // 如果想要达到说去除蓝色通道的值就把该通道的值取零然后在合并通道此时其余通道值不变，而蓝色通道的值为0，因而达到了目的

    // 此时我去除了blue 通道的颜色，图片是红绿混合成黄色
    // mat_vertor[1] = 0;
    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());

    int from_to[] = {0, 2, 1, 1, 2, 0};
    // 第一个参数是Mat指针，可以传Mat数组进来，后面就是传进去几个，第三个参数就是混合到那里
    // 最重要的就是fromTo参数，例如上面的就是，交换0和2通道 蓝红通道
    cv::mixChannels(&image, 1, &dst, 1, from_to, 3);

    // cv::merge(mat_vertor, dst);
    Show(image, dst, "image", "dst");
}

void MyCV::TextInRang(cv::Mat &image)
{
    // 转化成hsv
    cv::Mat hsv;
    cv::cvtColor(image, hsv, cv::COLOR_BGR2HSV);
    cv::Mat mask;
    // 仅仅常用于背景与主体颜色有颜色差距，且背景为纯色的图像
    // 第二个参数是背景颜色对应表格的最小值，第三个参数对应最大值，第四个参数就是提取到的主体，白色背景黑色为提取对象
    cv::inRange(hsv, cv::Scalar(0, 0, 221), cv::Scalar(180, 30, 255), mask);
    Show(image, mask, "image", "mask");
    // 创建一个全红背景图像
    cv::Mat redBack = cv::Mat::zeros(image.size(), image.type());
    redBack = cv::Scalar(40, 40, 200);
    // 把mask取反，此时为黑色背景，白色为主体
    cv::bitwise_not(mask, mask);
    // 因为copyTo函数的要求就是会提取有数值的部分到redBack中，经过取反mask中的主体为白色有数值，背景为黑色（0），此时就会把主体复制到红色背景当中。
    image.copyTo(redBack, mask);
    Show(redBack, mask, "redBack", "mask");
}

void MyCV::GetMinMaxLocAndMeanStddev(cv::Mat &image)
{
    double minv;
    double maxv;
    cv::Point minLoc;
    cv::Point maxLoc;
    // 由于是三通道的因此需要一个容器来装三个通道的值，minMaxLoc函数默认的是灰度单通道的
    std::vector<cv::Mat> mv;
    // 分离函数
    cv::split(image, mv);
    // 获得单通道的最小值和最大值并且获得位置Point
    for (int i(0); i < mv.size(); i++)
    {
        cv::minMaxLoc(mv[i], &minv, &maxv, &minLoc, &maxLoc);
        std::cout << "Channel No." << i << std::endl
                  << " minVal:" << minv << std::endl
                  << "maxVal:" << maxv << std::endl
                  << std::endl;
    }
    // 均值，标准差
    cv::Scalar mean, stddev;
    // 求出图像各通道均值和标准差
    cv::meanStdDev(image, mean, stddev);
    std::cout << "means:" << mean << std::endl
              << "stddev:" << stddev << std::endl;
    Show(image);
}

void MyCV::TextDarwRectangleAndCircle(cv::Mat &image)
{
    cv::Mat bg = cv::Mat::zeros(image.size(), image.type());
    cv::Mat dst = bg.clone();
    cv::circle(bg, cv::Point(400, 400), 50, cv::Scalar(255, 0, 0), -1, 8);
    cv::rectangle(bg, cv::Rect(100, 100, 300, 300), cv::Scalar(0, 0, 255), -1, 8);
    cv::line(bg, cv::Point(100, 100), cv::Point(800, 800), cv::Scalar(0, 255, 0), 4, 8);
    // 椭圆
    cv::ellipse(bg, cv::RotatedRect(cv::Point(400, 400), cv::Size(100, 300), 60), cv::Scalar(255, 255, 255), 1, 5);
    // 混合，把圆矩形线等等画在bg上然后按照权重混合。
    cv::addWeighted(image, 0.5, bg, 0.5, 0, dst);
    Show(dst);
}

void MyCV::TextRandomDrawLine()
{
    cv::Mat bg = cv::Mat::zeros(cv::Size(1200, 800), CV_8UC3);
    NamedAndResizeWindow("random line");
    int w = bg.cols;
    int h = bg.rows;
    // 生成随机数 参数是种子
    cv::RNG rng(12345);
    while (true)
    {
        // 按下esc退出
        int c = cv::waitKey(10);
        if (c == 27)
        {
            break;
        }
        // 生成0,1200之间的随机数
        int x1 = rng.uniform(0, w);
        int x2 = rng.uniform(0, w);

        int y1 = rng.uniform(0, h);
        int y2 = rng.uniform(0, h);
        // 清屏
        // bg = cv::Scalar(0, 0, 0);
        cv::line(bg, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), 1);
        cv::imshow("random line", bg);
    }
    cv::destroyAllWindows();
}

void MyCV::TextFillPolyPolylinesDrawContours()
{
    cv::Mat bg = cv::Mat::zeros(cv::Size(1200, 800), CV_8UC3);
    cv::Point p0(0, 0);
    cv::Point p1(100, 100);
    cv::Point p2(50, 400);
    cv::Point p3(100, 500);
    cv::Point p4(500, 600);
    cv::Point p5(900, 300);
    cv::Point p6(400, 100);
    // 点集
    std::vector<cv::Point> pts1;
    pts1.push_back(p1);
    pts1.push_back(p2);
    pts1.push_back(p3);
    pts1.push_back(p4);
    pts1.push_back(p5);
    pts1.push_back(p6);
    std::vector<cv::Point> pts2(pts1);
    pts2.push_back(p0);
    // 多个点集
    std::vector<std::vector<cv::Point>> contours;
    contours.push_back(pts1);
    contours.push_back(pts2);

    // 方式一：
    // 既可以描边也可以填充，而且不止可以画一个，因为你传进去的是多个点集，第三个参数就是选择点集下标，从0开始，如果想全都打印出来就-1
    // 后面常见的-1填充，正数就是线条粗细
    cv::drawContours(bg, contours, 1, cv::Scalar(0, 0, 255), 3);
    Show(bg);

    // 方式二：
    // 如果用这种方式polylines就是描边，ture那个参数就是是否封闭，需要注意点就是该函数的thickness的参数只能大于0，毕竟只能描边
    cv::polylines(bg, pts2, true, cv::Scalar(0, 255, 255), 4, cv::LINE_AA);
    // 填充
    cv::fillPoly(bg, pts2, cv::Scalar(255, 255, 0));
    Show(bg, "draw");
}

// @ private

void MyCV::NamedAndResizeWindow(const char *winname)
{
    cv::namedWindow(winname, cv::WINDOW_NORMAL);
    cv::resizeWindow(winname, cv::Size(1200, 800));
}

void MyCV::PrintMenu()
{
    std::cout << "0:Come back initial image" << std::endl;
    std::cout << "1: BGR to Gray" << std::endl;
    std::cout << "2:BGR to HSV" << std::endl;
    std::cout << "3:Inverse Color" << std::endl;
    std::cout << "4:Trackbar change color and contrast" << std::endl;
    std::cout << "5:Show different color style" << std::endl;
    std::cout << "+:brightness add 50" << std::endl;
    std::cout << "-:brightness subtract 50" << std::endl;
    std::cout << "*:brightness mutliply 5" << std::endl;
    std::cout << "/:brightness divide 5" << std::endl;
}

// @ static

void MyCV::ChangeBrightness(int b, void *userdata)
{
    // 承接image
    cv::Mat image = *((cv::Mat *)userdata);
    // 辅助图片初始化为0
    cv::Mat temp = cv::Mat::zeros(image.size(), image.type());
    // 目的地
    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
    // 回调函数里面的重点，第一个的参数是image图片，第二个是第一张图片的权重，第三个参数是第二张图片，第四个参数是第二张图片的权重，第五个参数是一个double常数，第六个是目的地
    cv::addWeighted(image, 1.0, temp, 0.0, (double)b - 50.0, dst);
    // 这个函数的作用就是按照公式把第一张图片乘第一个权重，加第二张乘权重，加一个常数，完成图片的混合。
    // 在这里调整亮度我只需要把每一个像素点的值加减即可因此1.0权重，第二张0.0,在常数那里控制亮度变化
    // 这里的算法就是让b-50.0传进来默认的b是50,一减就是0默认不加也不减然后最小就可以-50最大就可以+50
    cv::imshow("image_", dst);
}
// 当你拖动滑动条时，首先改变的是brightness（亮度）或者contrast（对比度）的值,
// 然后createTrackbar函数会调用相应的回调函数，这些回调函数会根据新的brightness或者contrast的值对图像进行修改，
// 最后通过imshow函数显示修改后的图像。整个过程就是通过滑动条的变化触发回调函数，从而实现图像的动态调整。
void MyCV::ChangeContrast(int b, void *userdata)
{
    cv::Mat image = *((cv::Mat *)userdata);
    cv::Mat temp = cv::Mat::zeros(image.size(), image.type());
    cv::Mat dst = cv::Mat::zeros(image.size(), image.type());
    // 对比度范围是0-5
    // 传进来默认是1
    double contrast = b / 100.0;
    cv::addWeighted(image, contrast, temp, 0.0, 0, dst);
    cv::imshow("image_", dst);
}
// 真离谱 本来是自己想法写的，有点瑕疵，然后就对着敲，结果一直是这样我也不知到为啥哎不管了。
cv::Point sp(-1, -1);
cv::Point ep(-1, -1);
cv::Mat temp;

void MyCV::OnDraw(int event, int x, int y, int flags, void *userdata)
{
    cv::Mat &image = *((cv::Mat *)userdata);

    if (event == cv::EVENT_LBUTTONDOWN)
    {
        sp.x = x;
        sp.y = y;
        std::cout << "start point: " << sp << std::endl;
    }
    else if (event == cv::EVENT_LBUTTONUP)
    {
        ep.x = x;
        ep.y = y;
        int dx = std::abs(ep.x - sp.x);
        int dy = std::abs(ep.y - sp.y);
        if (dx > 0 && dy > 0)
        {
            cv::Rect box(sp, ep);
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
            temp.copyTo(image);  // Restore the original image
            int dx = std::abs(ep.x - sp.x);
            int dy = std::abs(ep.y - sp.y);
            if (dx > 0 && dy > 0)
            {
                cv::Rect box(sp, ep);
                cv::rectangle(image, box, cv::Scalar(0, 0, 255), 4, cv::LINE_AA);
                cv::imshow("mouse drawing", image);
            }
        }
    }
}

void MyCV::MouseDrawing(cv::Mat &image)
{
    cv::namedWindow("mouse drawing", cv::WINDOW_NORMAL);
    cv::resizeWindow("mouse drawing", 1200, 800);
    cv::setMouseCallback("mouse drawing", OnDraw, (void *)&image);
    temp = image.clone();  // Clone the image for temporary drawing
    cv::imshow("mouse drawing", image);
}

// 需要特别注意的是，在多文件处理中，静态成员变量需要拿到.h文件之外去定义，否则会发生重复定义
// MyCV *MyCV::instance = nullptr;