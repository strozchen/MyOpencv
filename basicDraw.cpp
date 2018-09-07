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
	//ͼ����㣬�յ㣬��ɫ���߿�����
	line(pic, Point(x0, y0), Point(x1, y1), Scalar(0, 0, 255), thickness, lineType);
	imshow(picName, pic);
	return 0;
}
int basicDraw::drawEllipse(int x,int y,int angle)
{

	//ͼ��Բ�ģ���x�᳤��y�᳤������ת�Ƕȣ���ʼ�Ƕȣ������Ƕȡ�˳ʱ�롿����ɫ���߿�����
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
	//ͼ��Բ�ģ��뾶����ɫ���߿�����
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
	//ͼ�񣬵�λ�ã���ά���飩����������һλ���飩���������������ɫ������
	fillPoly(pic,ptr,num,1,Scalar(255, 0, 0), lineType);
	imshow(picName, pic);
	return 0;
}