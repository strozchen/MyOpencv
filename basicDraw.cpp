#include "basicDraw.h"
#define HIGHT 1000
#define WEIGHT 1000

int thickness = 2;
int lineType = 8;

basicDraw::basicDraw()
{
	picName = "this is picture";
	hight = HIGHT;
	weight = WEIGHT;
	pic = Mat::zeros(hight, weight, CV_8UC3);
}


basicDraw::~basicDraw()
{
}


int basicDraw::drawLine(int x0,int y0,int x1,int y1)
{
	//图像，起点，终点，颜色，线宽，线型
	line(pic, Point(x0, y0), Point(x1, y1), Scalar(0, 0, 255), thickness, lineType);
	imshow(picName, pic);
	return 0;
}
int basicDraw::drawEllipse(int x,int y,int angle)
{

	//图像，圆心，（x轴长，y轴长），旋转角度，起始角度，结束角度【顺时针】，颜色，线宽，线型
	ellipse(pic, Point(x, y), Size(25,50),angle,0,300,Scalar(0, 0, 255), thickness, lineType);
	imshow(picName, pic);
	return 0;
}
int basicDraw::drawRectangle(int x0, int y0, int x1, int y1)
{
	rectangle(pic, Point(x0, y0), Point(x1, y1), Scalar(255, 255, 0), thickness, lineType);
	imshow(picName, pic);
	return 0;
}
int basicDraw::drawCircle(int x,int y,double radius)
{
	//图像，圆心，半径，颜色，线宽，线型
	circle(pic, Point(x, y), radius, Scalar(0, 255, 0), thickness, lineType);
	imshow(picName, pic);
	return 0;
}
int basicDraw::drawFilledpolygon()
{
	Point points[1][4];
	points[0][0] = Point(100, 100);
	points[0][1] = Point(400, 100);
	points[0][2] = Point(700, 500);
	points[0][3] = Point(200, 600);
	const Point* ptr[1] = { points[0] };
	int num[] = { 4 };
	//图像，点位置（二维数组），点数量（一位数组），多边形数量，颜色，线型
	fillPoly(pic,ptr,num,1,Scalar(255, 0, 0), lineType);
	imshow(picName, pic);
	return 0;
}