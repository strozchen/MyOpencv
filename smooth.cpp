#include "smooth.h"


smooth::smooth()
{
}


smooth::~smooth()
{
}
//可以直接使用blur类函数代替smooth
void smooth::dosmooth(Mat img)
{
	namedWindow("show", CV_WINDOW_NORMAL);
	CvMat rs=img;
	cvSmooth(&rs, &rs, CV_GAUSSIAN, 3, 3, 0, 0);
	Mat s = Mat::Mat(&rs);
	imshow("show", s);
	waitKey();
	
}