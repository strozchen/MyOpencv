#include "main.h"
using namespace cv;
using namespace std;
int main()
{
	Mat img = imread("F:\\images\\pic\\44.bmp",0);  //ͼƬ·��
	
	myWatershed ws=myWatershed();
	ws.doWatershed(img);


	return 0;
}