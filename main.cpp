#include "main.h"
using namespace cv;
using namespace std;
int main()
{
	//Mat img1 = (Mat_<uchar>(2, 2) << 233, 0, 0, 233);
	//Mat img2 = (Mat_<uchar>(2, 2) << 1, 0, 1, 0);
	//Mat rs = img1&img2;
	Mat img = imread("F:\\images\\lena.png");

	myCalcBackProject mc;
	mc.doCalcBackProject(img);

	return 0;
}