#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void main()
{
	Mat cframe ,vFrame , qrlmage , wFrame;
	std::vector <Point2f> bbox;
	std::string data;
	VideoCapture camera(0) , video;
	QRCodeDetector qr;
	double width, height;
	std::vector<Point2f>v_bbox;

	while (true)
	{
		//camera.read(frame);
		camera >> cframe;
		data = qr.detectAndDecode(cframe, bbox, qrlmage);
		if (data.length() > 0)
		{
			if (!video.isOpened())
			{	video.open("../data/" + data);
				width = video.get(CAP_PROP_FRAME_WIDTH);
				height = video.get(CAP_PROP_FRAME_HEIGHT);
				v_bbox.push_back(Point2f(0, 0));
				v_bbox.push_back(Point2f(width, 0));
				v_bbox.push_back(Point2f(width, height));
				v_bbox.push_back(Point2f(0, height));
			}
			Mat H =findHomography(v_bbox, bbox);
			video >> vFrame;
			warpPerspective(vFrame, wFrame, H, cframe.size());
		
			imshow("wFrame", wFrame);

			//cout << "data : " << data << endl;

			imshow("qrlmage", qrlmage);

		}
		imshow("frame", cframe);
		waitKey(1);
	}
}