/* file name: main.cpp
 * programmer: Roy T Wu
 * Project: OpenCV demo*/

#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

using std::cout; 
using std::endl;
using std::vector;
using std::string; 


int main()
{
	cv::Mat test(100, 100, CV_8U, cv::Scalar::all(150));
	cv::imshow("test_window", test);
	cv::waitKey(0); //wait infinitely until any keystroke in the window

    return 0;
}

