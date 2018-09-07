#include "mydft.h"

//离散傅里叶变换


mydft::mydft()
{
}


mydft::~mydft()
{
}

int mydft::dodft(cv::Mat img)
{
	using namespace cv;
	Mat I = img;
	if (I.empty())
		return -1;

	Mat padded;
	int m = getOptimalDFTSize(I.rows);
	int n = getOptimalDFTSize(I.cols);
	//使用0扩充原始矩阵至合适大小
	copyMakeBorder(I, padded,0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexI;
	//合并另一个全0矩阵
	merge(planes, 2, complexI);
	//执行傅里叶变换
	cv::dft(complexI, complexI);

	split(complexI, planes);
	magnitude(planes[0], planes[1], planes[0]);
	Mat magI = planes[0];

	magI += Scalar::all(1);
	log(magI, magI);
	magI = magI(Rect(0, 0, magI.cols&-2, magI.rows&-2));//-2在计算机以补码形式储存（1111 1111 1111 1110），做逻辑与操作可以去掉奇数列/行

	int cx = magI.cols / 2;
	int cy = magI.rows / 2;

	Mat q0(magI, Rect(0, 0, cx, cy));
	Mat q1(magI, Rect(0, 0, cx, cy));
	Mat q2(magI, Rect(0, 0, cx, cy));
	Mat q3(magI, Rect(0, 0, cx, cy));

	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);

	normalize(magI, magI, 0, 1, CV_MINMAX);
	namedWindow("Input Image", WINDOW_NORMAL);
	namedWindow("specturm magnitude", WINDOW_NORMAL);
	imshow("Input Image", I);
	imshow("specturm magnitude", magI);
	waitKey();
	return 0;


}