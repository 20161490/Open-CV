#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const string dataPath = "../data/Practice5/";
const string objFileName = "Dominion.jpg";
const string videoFileName = "Dominion.mp4";

int main(int argc, char** argv)
{
    VideoCapture camera(0);
    VideoCapture video(dataPath + videoFileName);
    Mat obj = imread(dataPath + objFileName);

    int v_w = video.get(CAP_PROP_FRAME_WIDTH);
    int v_h = video.get(CAP_PROP_FRAME_HEIGHT);
    int o_w = obj.cols;
    int o_h = obj.rows;

    Mat sMask(Size(v_w, v_h), CV_8U, Scalar(255));

    vector<Point2f> oCorners{ Point2f(0,0), Point2f(o_w,0), Point2f(o_w,o_h), Point2f(0,o_h) };
    vector<Point2f> vCorners{ Point2f(0,0), Point2f(o_w,0), Point2f(o_w,o_h), Point2f(0,o_h) };

    Mat Hv2o = findHomography(vCorners, oCorners);

    vector<KeyPoint> objKPs;
    Mat objDesc;

    Ptr<Feature2D> sift = SIFT::create();

    sift->detectAndCompute(obj, Mat(), objKPs, objDesc);
    BFMatcher matcher(NORM_L2SQR);

    while (true)
    {
        vector<KeyPoint> camKPs;
        Mat cam, camDesc;
        vector<DMatch> matches;

        camera >> cam;
        sift->detectAndCompute(cam, Mat(), camKPs, camDesc);
        matcher.match(objDesc, camDesc, matches);

        vector<Point2f> objPoints, camPoints;

        for (int i = 0; i < matches.size(); i++)
        {
            objPoints.push_back(objKPs[matches[i].queryIdx].pt);
            camPoints.push_back(camKPs[matches[i].trainIdx].pt);
        }

        Mat inlier;
        Mat Ho2c = findHomography(objPoints, camPoints, RANSAC, 3.0, inlier);
        int nlnlier = countNonZero(inlier);
        if (nlnlier >= 75)
        {
            Mat Hv2c = Ho2c * Hv2o;
            Mat vid;
            video >> vid;

            Mat wVid, wMask;
            warpPerspective(sMask, wMask, Hv2c, cam.size());
            warpPerspective(vid, wVid, Hv2c, cam.size());

            wVid.copyTo(cam, wMask);
        }
        else
        {
            cout << "no object" << endl;
        }
        imshow("cam", cam);
        waitKey(1);
    }
    return 0;
}



