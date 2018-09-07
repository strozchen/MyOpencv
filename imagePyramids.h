#pragma once
#include <string>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <highgui\highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class imagePyramids
{
public:
	imagePyramids();
	~imagePyramids();

	int pyrup(Mat* img,Mat* dst,int k);
	int pyrdown(Mat* img, Mat* dst, int k);
};

