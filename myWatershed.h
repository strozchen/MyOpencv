#pragma once
#include <opencv2\opencv.hpp>
#include <highgui\highgui.hpp>
#include <imgproc\imgproc.hpp>
using namespace cv;
using namespace std;
class myWatershed
{
public:
	myWatershed();
	~myWatershed();
	void doWatershed(Mat img);
	static void on_Mouse(int event, int x, int y, int flags, void*);
	Mat rs;
	Mat mask;
	Point* prevPt;


};

