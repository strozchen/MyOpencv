#include "main.h"
using namespace cv;
using namespace std;
int main()
{
	//basicDraw myDraw;
	//myDraw.drawRectangle(100,100,200,200);



	cvfile f;
	f.writefile();
	f.readfile();



	//Mat img = imread("F:\\images\\LinuxLogo.jpg",0);  //Í¼Æ¬Â·¾¶

	//Mat img = imread("F:\\images\\pic\\222.bmp",0);  //Í¼Æ¬Â·¾¶
	//Mat src_change;
	//Mat mid,rs;
	//Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	//threshold(img, src_change, 130, 255, CV_THRESH_BINARY);
	////adaptiveThreshold(img, src_change, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 3, 5);
	//erode(src_change, src_change, element);
	//dilate(src_change, src_change, element);

	//blur(src_change, src_change, Size(3, 3));
	//Mat roi = src_change(Rect(1100, 800, 300, 300));
	//Canny(roi, roi, 50, 255, 3);
	//findcounters ft;
	//ft.dofind(roi);
	
	
	/*rs = src_change.clone();
	cvtColor(rs, rs, CV_GRAY2BGR);
	namedWindow("ddd", WINDOW_NORMAL);
	line(rs, Point(1100, 800), Point(1400, 800),Scalar(0,0,255),2,8);
	line(rs, Point(1100, 800), Point(1100, 1100), Scalar(0, 0, 255),2,8);
	line(rs, Point(1400, 1100), Point(1400, 800), Scalar(0, 0, 255), 2,8);
	line(rs, Point(1400, 1100), Point(1100,1100), Scalar(0, 0, 255),2,8);
	rectangle(rs, Point(1000,800),Point(1400,1200), Scalar(0, 255, 255), -1);
	imshow("ddd", rs);
	waitKey();*/

	//Mat a = Mat::zeros(img.size(), img.type());
	//Mat b = Mat::zeros(img.size(), img.type());
	//Mat c=Mat::zeros(img.size(), img.type());
	//
	//uchar* p;
	//int n = img.channels();
	//for (int i = 0; i < img.rows; i++)
	//{
	//	p = img.ptr<uchar>(i);
	//	for (int j = 0; j < img.cols*n; j=j+n)
	//	{
	//		a.at<uchar>(i,j) = p[j];
	//		b.at<uchar>(i, j + 1) = p[j + 1];
	//		c.at<uchar>(i, j + 2) = p[j + 2];
	//	}
	//}
	//cvtColor(a, a, CV_BGR2GRAY);
	//cvtColor(b, b, CV_BGR2GRAY);
	//cvtColor(c, c, CV_BGR2GRAY);

	//threshold(c, c, 20, 255, CV_THRESH_BINARY);
	//Canny(c, c, 0, 30, 3);
	//Mat mapx;
	//mapx.create(img.size(), CV_32FC1);

	//Mat mid,rs;
	//Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	////¸¯Ê´
	//erode(img, img, element);
	////ÅòÕÍ
	//dilate(img, img, element);

	//threshold(img, img, 150, 255, THRESH_BINARY);
	
	//Canny(img, mid, 50, 200, 3);
	
	//cvtColor(mid, rs, CV_GRAY2BGR);
	//vector<Vec2f> lines;
	//HoughLines(roi, lines, 1, CV_PI / 60,80, 0, 0);
	//rs = roi.clone();
	//cvtColor(rs, rs, CV_GRAY2BGR);
	//for (int i = 0; i < lines.size(); i++)
	//{
	//	float rho = lines[i][0];
	//	float theta = lines[i][1];
	//	Point pt1, pt2;
	//	double a = cos(theta);
	//	double b = sin(theta);
	//	double x0 = a*rho;
	//	double y0 = b*rho;
	//	pt1.x = cvRound(x0 + 1000 * (-b));
	//	pt1.y = cvRound(y0 + 1000 * a);
	//	pt2.x = cvRound(x0 - 1000 * (-b));
	//	pt2.y = cvRound(y0 - 1000 * a);
	//	line(rs, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	//}

	//imshow("origin", img);
	//imshow("hough", rs);
	////ÅòÕÍ
	//dilate(src_change, src_change, element);
	//;
	////Í¼Ïñ¶þÖµ»¯£¬Í»³öÂÖÀª
	//threshold(src_change, src_change, 100, 255, CV_THRESH_BINARY);
	//cvtColor(src_change, src_change, CV_BGR2GRAY);
	////¾ùÖµÂË²¨£¬Ä£ºýÍ¼Ïñ
	//blur(src_change, src_change, Size(1, 1));
	//namedWindow("src", WINDOW_NORMAL);
	//imshow("src", src_change);
	////±ßÔµ¼ì²â
	//Canny(src_change, src_change, 0, 30, 3);
	//Mat green, blue, red,rs;
	//vector<Mat> bgr;
	//split(img, bgr);
	//blue = bgr.at(0);
	//green = bgr.at(1);
	//red = bgr.at(2);
	//merge(bgr, rs);
	
	//for (int i = 1; i < blue.rows; i++)
	//{
	//	for (int j = 1; j < blue.cols/3; j++)
	//	{
	//		//cout << blue.at<Vec3b>(i,j) << endl;
	//		blue.at<Vec3b>(i, j)[1] = 255;
	//		blue.at<Vec3b>(i, j)[2] = 255;
	//		//cout << blue.at<Vec3b>(i, j) << endl;
	//	}
	//}
	//cout << red.type()<<endl;
	//blue = Mat::zeros(blue.size(), CV_8UC3);
	//red = Mat::zeros(red.size(), CV_8UC3);
	//bgr.clear();
	//bgr.push_back(blue);
	//bgr.push_back(red);
	//bgr.push_back(green);



	waitKey(0);
	return 0;
}