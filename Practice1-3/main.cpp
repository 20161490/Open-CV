#include<opencv2/opencv.hpp>

using namespace cv;

void main()
{
	Mat win = imread("../data/windows.jpg");
	Mat ryan = imread("../data/ryan.bmp");


	Mat roi = win(Rect(100,100,ryan.cols,ryan.rows));

	ryan.copyTo(roi);

	imshow("img", win);
	imshow("ryan", ryan); 
	imshow("roi", roi);
	waitKey();
}