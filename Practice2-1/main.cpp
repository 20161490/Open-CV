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
			cout << "data : " << data << endl;
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