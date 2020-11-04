#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat dstMat, srcMat = imread("D:\\pic\\xietu.jpg"),srcMat_hui= imread("D:\\pic\\xietu.jpg",0);
	int heigh = srcMat_hui.rows;
	int width = srcMat_hui.cols;
	//cout << heigh << "  " << width << endl;
	int p = srcMat_hui.at<uchar>(0, 0);
	//cout << p << endl;
	int pt_0_r = 0, pt_0_c = 0, pt_1_r = 0, pt_1_c = 0, pt_2_r = 0, pt_2_c = 0;
	//const Point2f pt_src[3] = {Point2f(0,0),Point2f(0,0),Point2f(0,0)};
	const Point2f pt_dst[3] = { Point2f(0,0),Point2f(0,heigh-1),Point2f(width-1,heigh-1) };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < width; j++) {
			if (p - srcMat_hui.at<uchar>(i, j)>5) {
				pt_0_r = j;
				pt_0_c = i;
				break;
			}
		}
		if (pt_0_r != 0 && pt_0_c != 0)break;
	}
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < heigh; i++) {
			if (p - srcMat_hui.at<uchar>(i, j)>5) {
				pt_1_r = j;
				pt_1_c = i;
				break;
			}
		}
		if (pt_1_r != 0 && pt_1_c != 0)break;
	}
	for (int i = heigh-3; i < heigh; i++) {
		for (int j = 0; j < width; j++) {
			if (p - srcMat_hui.at<uchar>(i, j)>5) {
				pt_2_r = j;
				pt_2_c = i;
				break;
			}
		}
		if (pt_2_r != 0 && pt_2_c != 0)break;
	}
	//cout << pt_0_r << "  " << pt_0_c << "   " << pt_1_r << "  " << pt_1_c << "  " << pt_2_r << "  " << pt_2_c << endl;
	const Point2f pt_src[3] = {Point2f(pt_0_r,pt_0_c),Point2f(pt_1_r,pt_1_c),Point2f(pt_2_r,pt_2_c)};
	Mat affine_matrix = getAffineTransform(pt_src, pt_dst);
	warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);

}