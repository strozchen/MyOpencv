#include "imagePyramids.h"


imagePyramids::imagePyramids()
{
}


imagePyramids::~imagePyramids()
{
}


int imagePyramids::pyrup(Mat* img,Mat* dst,int k)
{
	Mat tmp;
	if (!img->data) return -1;
	tmp = *img;
	pyrUp(*img, *dst, Size(tmp.cols * k, tmp.rows * k));
	return 1;

}


int imagePyramids::pyrdown(Mat* img, Mat* dst, int k)
{
	Mat tmp;
	if (!img->data) return -1;
	tmp = *img;
	pyrDown(*img, *dst, Size(tmp.cols / k, tmp.rows / k));
	return 1;
}