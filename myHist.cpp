#include "myHist.h"


myHist::myHist()
{
}


myHist::~myHist()
{
}
//绘制H-S直方图
MatND myHist::do2dHist(Mat img)
{
	Mat src;
	cvtColor(img, src, COLOR_BGR2HSV);
	int binNum = 30;//色调分30级
	int SaBinNum = 30;//饱和度分30级
	int histSize[] = { binNum, SaBinNum };
	float hueRanges[] = { 0, 180 };//色调变换范围
	float SaRange[] = { 0, 255 };//饱和度变化范围
	const float* ranges[] = { hueRanges, SaRange };//此处必须是const 类型
	MatND dstHist;
	int chanels[] = { 0, 1 };//计算的通道
	calcHist(&src,//输入图像，必须为CV_8U OR CV_32F
			1,//输入图像个数
			chanels,//需要计算通道数
			Mat(),//蒙版，8位同尺寸图
			dstHist,//输出的二维数组
			2,//直方图维度
			histSize,//每个维度中保存的数组长度
			ranges,//每个维度取值范围
			true,//直方图是否均匀，默认true
			false);//累计标识符
	double MaxValue = 0;
	minMaxLoc(dstHist, 0, &MaxValue, 0, 0);// 获取最大值
	int scale = 10;
	Mat histImg = Mat::zeros(SaBinNum*scale, binNum*scale, CV_8UC3);
	for (int hue = 1; hue < binNum; hue++)
	{
		for (int sa = 0; sa < SaBinNum; sa++)
		{
			float binvalue = dstHist.at<float>(hue, sa);
			int intensity = cvRound(binvalue * 255 / MaxValue);
			rectangle(histImg, Point(hue*scale, sa*scale), Point((hue + 1)*scale - 1, (sa + 1)*scale - 1), Scalar::all(intensity),CV_FILLED);
		}
	}
	imshow("or",src);
	imshow("hs", histImg);
	waitKey();
	return dstHist;
}
//绘制灰度直方图，1维
MatND myHist::dohist(Mat img)
{
	Mat rs = img;
	MatND dstHist;
	int dims = 1;
	float grayRanges[] = { 0, 255 };
	const float* ranges[] = { grayRanges };
	int size = 256;
	int chanels = 0;
	calcHist(&rs, 1, &chanels, Mat(), dstHist, dims, &size, ranges);
	int scale = 1;
	double MaxValue = 0;
	double MinValue = 0;
	minMaxLoc(dstHist, &MinValue, &MaxValue, 0, 0);
	int hpt = saturate_cast<int>(0.9*size);
	Mat dstImag(size*scale, size, CV_8U, Scalar(0));
	for (int i = 0; i < 256; i++)
	{
		float binValue = dstHist.at<float>(i);
		int realvalue = saturate_cast<int>(binValue*hpt / MaxValue);
		rectangle(dstImag, Point(i*scale, size - 1), Point((i + 1)*scale - 1, size - realvalue), Scalar(255));

	}
	imshow("or", img);
	imshow("一维直方图", dstImag);
	waitKey();
	return dstHist;
}
//直方图均衡化
void myHist::eqhist(Mat img)
{
	Mat rs;
	equalizeHist(img, rs);
	dohist(img);
	waitKey();
	dohist(rs);
	
}

//计算直方图相关性
float myHist::calc(MatND h1, MatND h2,int i)
{
	//归一化
	normalize(h1, h1, 0, 1, NORM_MINMAX, -1, Mat());
	normalize(h2, h2, 0, 1, NORM_MINMAX, -1, Mat());
	//0 相关
	//1卡方
	//2相交
	//3 Bhattacharyya距离
	return compareHist(h1, h2, i);
}

//计算EMD直方图相关性
float myHist::calcEMD(MatND h1, MatND h2, int i)
{
	//归一化
	normalize(h1, h1, 0, 1, NORM_MINMAX, -1, Mat());
	normalize(h2, h2, 0, 1, NORM_MINMAX, -1, Mat());
	//1  CV_DIST_L1
	//2  CV_DIST_L2
	return EMD(h1, h2, CV_DIST_L2);
}