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
	//��ɢ����Ҷ�任
	int dodft(cv::Mat img);
};

