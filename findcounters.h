#pragma once
#include <string>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <highgui\highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
class findcounters
{
public:
	findcounters();
	~findcounters();

	int dofind(Mat img);
};

