#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <highgui\highgui.hpp>

using namespace cv;
using namespace std;
class myCalcBackProject
{
public:
	myCalcBackProject();
	~myCalcBackProject();

	int doCalcBackProject(Mat img);
};

