#include "myCalcBackProject.h"


myCalcBackProject::myCalcBackProject()
{
}


myCalcBackProject::~myCalcBackProject()
{
}

/*����ͶӰ����
void calcBackProject(
const Mat* images		��������
int nimages				��������ĸ���
const int* channels		��Ҫͳ�Ƶ�ͨ������
InputArray backProject	�����ֱ��ͼ
const float** ranges	Ŀ�귴��ͶӰ���󣬵�ͨ��
double scale=1			���������������
bool uniform=true		ָʾֱ��ͼ�Ƿ���ȵı�ʶ��
)
*/
/*
void mixChannels(
const Mat* src			��������
size_t nsrcs			��������ľ�����
Mat* dst				������飬�����ȳ�ʼ��
size_t ndsts			����������
const int* fromTo		ͨ�����ƵĹ���2����Ϊһ�飬ǰ�߶�Ӧ�����ͨ�������߶�Ӧ�����ͨ����i��
size_t npairs			fromTo�Ķ�Ӧ����
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

	imshow("����ͶӰͼ", backproj);
	int w = 400;
	int h = 400;
	int bin_w = cvRound((double)w / histSize);
	Mat histImg = Mat::zeros(w, h, CV_8UC3);
	for (int i = 0; i < g_bines; i++)
	{
		rectangle(histImg, Point(i*bin_w, h), Point((i + 1)*bin_w, h - cvRound(hist.at<float>(i)*h / 255.0)), Scalar(100, 123, 255), -1);
	}
	imshow("hist", histImg);

	imshow("ԭʼͼ", g_srcImage);

	waitKey();
	destroyAllWindows();
	return 0;
}