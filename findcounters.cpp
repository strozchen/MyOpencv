#include "findcounters.h"


findcounters::findcounters()
{
}


findcounters::~findcounters()
{
}

int findcounters::dofind(Mat img)
{
	if (!img.data) return -1;
	namedWindow("origin", WINDOW_NORMAL);
	imshow("origin", img);

	if (img.channels() > 1)
		cvtColor(img, img, CV_BGR2GRAY);
	Mat dst=Mat::zeros(img.rows,img.cols,CV_8UC3);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	//�ұ߽�
	//findContours(img, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	//ֻ��������
	findContours(img, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	////��ǰ����������������list�У������������������ȼ���ϵ
	//findContours(img, contours, hierarchy, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
	////retrieves all of the contours and reconstructs a full hierarchy of nested contours.
	//findContours(img, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	////stores absolutely all the contour points. 
	//findContours(img, contours, hierarchy, CV_CHAIN_APPROX_NONE, CV_CHAIN_APPROX_SIMPLE);
	////compresses horizontal, vertical, and diagonal segments and leaves only their end points. For example, an up-right rectangular contour is encoded with 4 points.
	//findContours(img, contours, hierarchy, CV_CHAIN_APPROX_SIMPLE, CV_CHAIN_APPROX_SIMPLE);
	//// applies one of the flavors of the Teh - Chin chain approximation algorithm��CV_CHAIN_APPROX_TC89_L1,CV_CHAIN_APPROX_TC89_KCOS��

	int index = 0;
	for (; index < contours.size(); index++)
	{
		Scalar color(rand() & 255, rand() & 255, rand()&255);
		//���߽磬ÿ�λ�һ��
		drawContours(dst, contours, index, color, 1, 8, hierarchy);

	}
	namedWindow("rs", WINDOW_NORMAL);
	imshow("rs", dst);
	return 1;
}
