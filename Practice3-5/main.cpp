#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const string imgPath = "../data/Practice3/butterfly.jpg";
const string imgPath2 = "../data/butterfly2.jpg";

int main(int argc, char** argv)
{
    Mat img = imread(imgPath), result;
    Mat img2 = imread(imgPath2), result2;


    vector<KeyPoint> kps;

    Ptr<Feature2D> sift = SIFT::create();
    Ptr<Feature2D> sift2 = SIFT::create();

    sift->detect(img, kps);
    sift2->detect(img2, kps);

    drawKeypoints(img, kps, result, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    drawKeypoints(img2, kps, result2, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

    imshow("result", result);
    imshow("result2", result2);
    waitKey();
    return 0;
}


