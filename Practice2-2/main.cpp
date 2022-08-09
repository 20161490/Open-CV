#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void main()
{
	Mat frame , qrlmage;
	std::vector <Point> bbox;
	std::string data;
	VideoCapture camera(0);
	QRCodeDetector qr;

	while (true)
	{
		//camera.read(frame);
		camera >> frame;
		data = qr.detectAndDecode(frame, bbox, qrlmage);
		if(data.length() > 0)
		{
			//cout << "data : " << data << endl;
			putText(frame, data, bbox[0], FONT_HERSHEY_COMPLEX, 1, Scalar(255, 0, 0), 2);
			line(frame, bbox[0], bbox[1], Scalar(0, 255, 0), 2);
			line(frame, bbox[1], bbox[2], Scalar(0, 255, 0), 2);
			line(frame, bbox[2], bbox[3], Scalar(0, 255, 0), 2);
			line(frame, bbox[3], bbox[0], Scalar(0, 255, 0), 2);

			for (int i = 0; i < bbox.size(); i++)
			{
				cout << bbox[i].x << ", " << bbox[i].y << endl;
			}
			imshow("qrlmage", qrlmage);

		}
		imshow("frame", frame);
		waitKey(1);
	}
}