#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void main()
{
	Mat cframe ,vFrame , qrlmage;
	std::vector <Point> bbox;
	std::string data;
	VideoCapture camera(0) , video;
	QRCodeDetector qr;

	while (true)
	{
		//camera.read(frame);
		camera >> cframe;
		data = qr.detectAndDecode(cframe, bbox, qrlmage);
		if(data.length() > 0)
		{
			if(!video.isOpened())
				video.open("../data/" + data);
			video >> vFrame;
			imshow("vFrame", vFrame);

			//cout << "data : " << data << endl;
			putText(cframe, data, bbox[0], FONT_HERSHEY_COMPLEX, 1, Scalar(255, 0, 0), 2);
			line(cframe, bbox[0], bbox[1], Scalar(0, 255, 0), 2);
			line(cframe, bbox[1], bbox[2], Scalar(0, 255, 0), 2);
			line(cframe, bbox[2], bbox[3], Scalar(0, 255, 0), 2);
			line(cframe, bbox[3], bbox[0], Scalar(0, 255, 0), 2);

			for (int i = 0; i < bbox.size(); i++)
			{
				cout << bbox[i].x << ", " << bbox[i].y << endl;
			}
			imshow("qrlmage", qrlmage);

		}
		imshow("frame", cframe);
		waitKey(1);
	}
}