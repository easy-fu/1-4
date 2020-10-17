#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
int main()
{
	cv::Mat srcM= imread("C:/Users/DELL/Desktop/1.jpg");
	cv::Mat shallowMat = srcM;
	cv::Mat deepMat = srcM.clone();
	int height = srcM.rows;
	int width = srcM.cols;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (srcM.at<Vec3b>(j, i)[0] + srcM.at<Vec3b>(j, i)[1] + srcM.at<Vec3b>(j, i)[2]) / 3;
			uchar threshold = 100;
			if (average > threshold)
				average = 255;
			else
				average = 0;
			srcM.at<Vec3b>(j, i)[0] = average;
			srcM.at<Vec3b>(j, i)[1] = average;
			srcM.at<Vec3b>(j, i)[2] = average;
		}
	}
	imshow("deepMat", deepMat);
	imshow("shallowMat", shallowMat);
	waitKey(0);
	return 0;

}