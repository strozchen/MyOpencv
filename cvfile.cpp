#include "cvfile.h"
using namespace cv;
using namespace std;

cvfile::cvfile()
{
}


cvfile::~cvfile()
{
}


//xml,ymalÎÄ¼þ¶ÁÐ´
void cvfile::writefile()
{
	FileStorage fs;
	fs.open("cfg.xml", FileStorage::WRITE);
	fs << "framecount" << 10;
	time_t rawtime = time(NULL);
	tm* t = localtime(&rawtime);
	fs << "calibrationDate" << asctime(t);
	Mat cameraMatrix = (Mat_<double>(3, 3) << 1000, 0, 320, 0, 1000, 240, 0, 0, 1);
	Mat distcoeffs = (Mat_<double>(5, 1) << 0.1, 0.01, -0.001, 0, 0);
	fs << "cameraMatrix" << cameraMatrix << "distcoeffs" << distcoeffs;
	fs << "features" << "[";
	for (int i = 0; i < 3; i++)
	{
		int x = rand() % 640;
		int y = rand() % 480;
		uchar lbp = rand() % 256;
		fs << "{:" << "x" << x << "y" << y << "lbp" << "[:";
		for (int j = 0; j < 8; j++)
		{
			fs << ((lbp >> j) & 1);
		}
		fs << "]" << "}";
	}
	fs << "]";
	fs.release();
}

void cvfile::readfile()
{
	FileStorage fs;
	fs.open("cfg.xml", FileStorage::READ);
	int frameCount = (int)fs["framecount"];
	string date;
	fs["calibrationDate"] >> date;

	Mat cameraMatrix, distcoeff;
	fs["cameraMatrix"] >> cameraMatrix;
	fs["distcoeffs"] >> distcoeff;

	cout << "framecount:" << frameCount << endl;
	cout << "calibrationDate:" << date << endl;
	cout << "cameraMatrix:" << cameraMatrix << endl;
	cout << "distcoeffs:" << distcoeff << endl;

	vector<uchar> lbpval;
	FileNode features = fs["features"];
	FileNodeIterator it = features.begin(), it_end = features.end();
	int index = 0;
	for (; it != it_end; it++, index++)
	{
		cout << "feature #" << index << ":";
		cout << "x=" << (int)(*it)["x"] << ", y=" << (int)(*it)["y"] << ", lbp:(";
		(*it)["lbp"] >> lbpval;
		for (int i = 0; i < lbpval.size(); i++)
			cout << " " << (int)lbpval[i];
		cout<< ")" << endl;
	}
	fs.release();
	getchar();

}