#include<opencv2/opencv.hpp>

using namespace cv;

void main()
{
	Mat win = imread("../data/windows.jpg");
	Mat ryan = imread("../data/ryan.png" , IMREAD_UNCHANGED);
	std::vector<Mat> channels;

	split(ryan, channels);

	Mat mask = channels[3];
	channels.pop_back();

	Mat color_ryan;
	merge(channels, color_ryan);
	
	Mat roi = win(Rect(100,100,ryan.cols,ryan.rows));

	color_ryan.copyTo(roi , mask);

	imshow("img", win);
	imshow("mask", mask);
	imshow("roi", roi); 
	waitKey();
}