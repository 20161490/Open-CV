#include<opencv2/opencv.hpp>

using namespace cv;

void main()
{
	Mat win = imread("../data/windows.jpg");
	Mat ryan = imread("../data/ryan.bmp");
	Mat bit(ryan.size() , CV_8U, Scalar(255));
	Mat gray , mask;
	cvtColor(ryan, gray, COLOR_BGR2GRAY);
	bitwise_xor(bit, gray, mask);

	Mat roi = win(Rect(100,100,ryan.cols,ryan.rows));

	ryan.copyTo(roi , mask);

	imshow("img", win);
	imshow("ryan", ryan); 
	imshow("gray", gray);
	imshow("bit", bit);
	imshow("mask", mask);
	imshow("roi", roi);
	waitKey();
}