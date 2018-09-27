#include "myCalcBackProject.h"


myCalcBackProject::myCalcBackProject()
{
}


myCalcBackProject::~myCalcBackProject()
{
}

/*反向投影函数
void calcBackProject(
const Mat* images		输入数组
int nimages				输入数组的个数
const int* channels		需要统计的通道索引
InputArray backProject	输入的直方图
const float** ranges	目标反向投影矩阵，单通道
double scale=1			输出方向缩放因子
bool uniform=true		指示直方图是否均匀的标识符
)
*/
/*
void mixChannels(
const Mat* src			输入数组
size_t nsrcs			输入数组的矩阵数
Mat* dst				输出数组，必须先初始化
size_t ndsts			输出数组个数
const int* fromTo		通道复制的规则，2个数为一组，前者对应输入的通道，后者对应输出的通道我i在
size_t npairs			fromTo的对应个数
)
*/
int myCalcBackProject::doCalcBackProject(Mat img)
{
	Mat g_srcImage;
	Mat g_hsvImage;
	Mat g_hueImage;
	int g_bines = 60;
	g_srcImage = img.clone();
	cvtColor(g_srcImage, g_hsvImage, COLOR_BGR2HSV);
	g_hueImage.create(g_hsvImage.size(), g_hsvImage.depth());
	int ch[] = { 0, 0 };
	mixChannels(&g_hsvImage, 1, &g_hueImage, 1, ch, 1);

	MatND hist;
	int histSize = MAX(g_bines, 2);
	float hue_range[] = { 0, 180 };
	const float* ranges = { hue_range };
	calcHist(&g_hueImage, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false);
	normalize(hist, hist, 0, 255, NORM_MINMAX, -1, Mat());
	MatND backproj;
	calcBackProject(&g_hueImage, 1, 0, hist, backproj, &ranges, 1, true);

	imshow("反向投影图", backproj);
	int w = 400;
	int h = 400;
	int bin_w = cvRound((double)w / histSize);
	Mat histImg = Mat::zeros(w, h, CV_8UC3);
	for (int i = 0; i < g_bines; i++)
	{
		rectangle(histImg, Point(i*bin_w, h), Point((i + 1)*bin_w, h - cvRound(hist.at<float>(i)*h / 255.0)), Scalar(100, 123, 255), -1);
	}
	imshow("hist", histImg);

	imshow("原始图", g_srcImage);

	waitKey();
	destroyAllWindows();
	return 0;
}