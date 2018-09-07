#pragma once
#include <opencv2\opencv.hpp>
#include <highgui\highgui.hpp>
#include <imgproc\imgproc.hpp>
#include <time.h>
class cvfile
{
public:
	cvfile();
	~cvfile();
	void writefile();
	void readfile();
};

