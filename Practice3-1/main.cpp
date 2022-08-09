#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const string dataPath = "../data/Practice3/3-1/";
const string queryFileName = "query.bmp";
const vector<string>targetFileName = {"1.bmp","2.bmp","3.bmp","4.bmp","5.bmp","6.bmp"};

Mat calcHist(Mat& input) // 입력 이미지의 한 픽셀은 1바이트 표현()
{
	Mat output(1, 256, CV_32F, Scalar(0));

	for (int i = 0; i < input.rows; i++)
		for (int j = 0; j < input.cols; j++)
			output.at<float>(input.at<uchar>(i, j))++;
	output /= input.total();
	return output;
}
double calcDistance(Mat& input1, Mat& input2)
{
	double distance = 0.0;

	for (int i = 0; i < input1.cols; i++)
		distance += (input1.at<float>(i) - input2.at<float>(i)) * (input1.at<float>(i) - input2.at<float>(i));
	
	return distance;
}

void main()
{
	Mat queryimg = imread(dataPath + queryFileName,IMREAD_GRAYSCALE);
	Mat queryVector = calcHist(queryimg);

	for (int i = 0; i < targetFileName.size(); i++)
	{
		Mat targetimg = imread(dataPath + targetFileName[i], IMREAD_GRAYSCALE);
		Mat targetVector = calcHist(targetimg);
		cout << calcDistance(targetVector, queryVector) << endl;
	}

}