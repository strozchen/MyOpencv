#pragma once
#include <opencv2\opencv.hpp>
#include <highgui\highgui.hpp>
#include <imgproc\imgproc.hpp>
using namespace cv;
using namespace std;
class myHist
{
public:
	myHist();
	~myHist();
	MatND do2dHist(Mat img);
	MatND dohist(Mat img);
	void eqhist(Mat img);
	float calc(MatND h1, MatND h2,int i);
	float calcEMD(MatND h1, MatND h2, int i);
};

