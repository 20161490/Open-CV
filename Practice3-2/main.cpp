#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const string dataPath = "../data/Practice3/3-2/";
const string queryFileName = "query.jpg";
const vector<string>targetFileName = { "1.jpg","2.jpg","3.jpg","4.jpg","5.jpg","6.jpg","7.jpg" ,"8.jpg" ,"9.jpg" ,"10.jpg",
"11.jpg", "12.jpg", "13.jpg", "14.jpg", "15.jpg", "16.jpg" ,"17.jpg", "18.jpg", "19.jpg", "20.jpg" ,"21.jpg" ,"22.jpg"
,"23.jpg" ,"24.jpg" ,"25.jpg" ,"26.jpg" ,"27.jpg" ,"28.jpg" ,"29.jpg" ,"30.jpg" ,"31.jpg" ,"32.jpg" ,"33.jpg","34.jpg"
,"35.jpg" ,"36.jpg" ,"37.jpg" ,"38.jpg" ,"39.jpg" ,"40.jpg" ,"41.jpg" ,"42.jpg" ,"43.jpg" ,"44.jpg" ,"45.jpg" ,"46.jpg" ,"47.jpg"
,"48.jpg" ,"49.jpg" ,"50.jpg" };

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