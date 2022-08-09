#include<opencv2/opencv.hpp>

using namespace cv;

void main()
{
	Mat img = imread("../data/windows.jpg");
	Mat gray , small , smallgray;
	cvtColor(img, gray, COLOR_BGR2GRAY);

	//int width = img.cols;
	//int height = img.rows;
	//resize(img, small, Size(width/2, height/2));

	resize(img, small, img.size()/2);
	cvtColor(small, smallgray, COLOR_BGR2GRAY);

	imshow("img", img);
	imshow("gray", gray);
	imshow("small", small);
	imshow("smallgray", smallgray);
	waitKey();
}