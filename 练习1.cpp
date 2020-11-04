#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat srcMat = imread("D:\\pic\\yb.jpg"),dstMat;
	Canny(srcMat, dstMat, 100, 180);
	imshow("src", dstMat);
	waitKey(0);
}