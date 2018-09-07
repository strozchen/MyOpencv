#include "myWarpAffine.h"
using namespace cv;
using namespace std;

myWarpAffine::myWarpAffine()
{
}


myWarpAffine::~myWarpAffine()
{
}


void myWarpAffine::dowf(Mat* img,Mat *rs)
{
	//二维坐标系变化
	double theta = 90;//旋转角度
	Point2f center = Point2f(160, 120);//旋转中心
	double scale = 1;//比例系数
	Mat m = getRotationMatrix2D(center, theta, scale);
	warpAffine(*img, *rs, m, Size(0.1, 0.1));
}
