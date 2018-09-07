#pragma once
#include <string>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <highgui\highgui.hpp>
#include <iostream>
class mydft
{
public:
	mydft();
	~mydft();
public:
	//¿Î…¢∏µ¿Ô“∂±‰ªª
	int dodft(cv::Mat img);
};

