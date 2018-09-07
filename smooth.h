#pragma once
#include <opencv2\opencv.hpp>
#include <highgui\highgui.hpp>
#include <imgproc\imgproc.hpp>
using namespace cv;
using namespace std;
class smooth
{
public:
	smooth();
	~smooth();
	void dosmooth(Mat img);
};

