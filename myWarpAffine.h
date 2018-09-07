#pragma once
#include <string>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <highgui\highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
class myWarpAffine
{
public:
	myWarpAffine();
	~myWarpAffine();
public :
	void dowf(Mat* img,Mat* rs);
	
};

