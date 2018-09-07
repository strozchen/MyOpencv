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
	//��ά����ϵ�仯
	double theta = 90;//��ת�Ƕ�
	Point2f center = Point2f(160, 120);//��ת����
	double scale = 1;//����ϵ��
	Mat m = getRotationMatrix2D(center, theta, scale);
	warpAffine(*img, *rs, m, Size(0.1, 0.1));
}
