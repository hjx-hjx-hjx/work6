#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;
string window_name = "dstMat";

void onTrackbar(int,void*data)
{
	cout << "aaa" << endl;
	Mat src = *(Mat*)(data);
	Mat dstMat;
	Canny(src, dstMat, 100,180);
	imshow(window_name, dstMat);
}

int main()
{
	int edgeThresh = 1;
	int minth = 20;
	int Maxth = 250;
	Mat srcMat;
	Mat gryMat;
	srcMat = imread("D:\\pic\\yb.jpg");
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
	//imshow("aa", gryMat);
	createTrackbar("edgeThresh", window_name, &minth, Maxth, onTrackbar,&gryMat);
	waitKey(0);

	return 0;
}