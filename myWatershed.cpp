#include "myWatershed.h"


myWatershed::myWatershed()
{
	prevPt = new Point(-1, -1);
}


myWatershed::~myWatershed()
{
	delete prevPt;
}

void myWatershed::doWatershed(Mat img)
{
	namedWindow("img", WINDOW_NORMAL);
	imshow("img", img);
	img.copyTo(rs);
	//rs = img.clone();
	cvtColor(rs, rs, CV_GRAY2BGR);
	Mat srcImg = rs.clone();
	mask = Mat::zeros(rs.rows,rs.cols, CV_8UC1);
	setMouseCallback("img", on_Mouse, this);
	waitKey();
	while (1)
	{
  		int c = waitKey(0);
		if ((char)c == 27)//esc退出
			break;
		if ((char)c == ' ')//空格处理图像
		{
			int i, j, compCount = 0;
			vector<vector<Point>> contours;
			vector<Vec4i> hierarchy;
			findContours(mask, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
			if (contours.empty())
				continue;
			Mat maskImg(mask.size(), CV_32S);
			maskImg = Scalar::all(0);
			for (int i = 0; i >=0; i=hierarchy[i][0],compCount++)
			{
				drawContours(maskImg, contours, i, Scalar::all(compCount + 1), -1, 8, hierarchy, INT_MAX);
			}
			if (compCount == 0)
				continue;
			vector<Vec3b> colorTab;
			for (j = 0; j < compCount; j++)
			{
				int b = theRNG().uniform(0, 255);
				int g = theRNG().uniform(0, 255);
				int r = theRNG().uniform(0, 255);
				colorTab.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
			}
			double dtime = (double)getTickCount();
			watershed(rs, maskImg);
			dtime = (double)getTickCount() - dtime;
			printf("\t处理时间=%gms\n", dtime*1000. / getTickFrequency());

			Mat watershedImg(maskImg.size(), CV_8UC3);
 			for (i = 0; i < maskImg.rows; i++)
			{
				for (j = 0; j < maskImg.cols; j++)
				{
					int index = maskImg.at<int>(i, j);
					if (index == -1)
						watershedImg.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
					else if (index <= 0 || index>compCount)
						watershedImg.at<Vec3b>(i,j) = Vec3b(0, 0, 0);
					else
					{
						watershedImg.at<Vec3b>(i, j) = colorTab[index - 1];
					}
				} 
			}
				watershedImg = watershedImg*0.5 + srcImg*0.5;
				namedWindow("watershed transform", WINDOW_NORMAL);
				imshow("watershed transform", watershedImg);
		}
				
	}


}
void myWatershed::on_Mouse(int event, int x, int y, int flags, void* param)
{
	myWatershed* tmp = (myWatershed*)param;
	//printf("%d %d\n", event, flags);
	if (x<0 || x>tmp->mask.cols || y<0 || y>tmp->mask.rows)
		return;
	if (event == EVENT_LBUTTONUP || !(flags&EVENT_FLAG_LBUTTON))
		*tmp->prevPt = Point(-1, -1);
	else if (EVENT_LBUTTONDOWN)
	{
		*tmp->prevPt = Point(x, y);
	}
	//else 
	if ((event == EVENT_MOUSEMOVE) && (flags&EVENT_FLAG_LBUTTON))
	{
		Point pt(x, y);
		if (tmp->prevPt->x < 0)
			*tmp->prevPt = pt;
		line(tmp->mask, *tmp->prevPt, pt, Scalar::all(255), 2, 2, 0);
		line(tmp->rs, *tmp->prevPt, pt, Scalar::all(255), 2, 2, 0);
		*tmp->prevPt = pt;
		imshow("img", tmp->rs);

	}
}