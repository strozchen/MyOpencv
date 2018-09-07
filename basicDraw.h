#pragma once
#include <string>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <highgui\highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
class basicDraw
{
public:
	basicDraw();
	~basicDraw();

	int drawLine(int x0, int y0, int x1, int y1);
	int drawEllipse(int x, int y, int angle);
	int drawRectangle(int x0, int y0, int x1, int y1);
	int drawCircle(int x, int y, double radius);
	int drawFilledpolygon();

public:
	string picName;
	Mat pic;
	int weight;
	int hight;
};


