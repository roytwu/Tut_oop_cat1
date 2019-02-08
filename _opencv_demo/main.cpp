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
	//cv::Mat test(100, 100, CV_8U, cv::Scalar::all(150));
	//cv::imshow("test_window", test);
	//cv::waitKey(0); //wait infinitely until any keystroke in the window

	//* make a 7x7 complex matrix filled with i+3j
	//* CV_32FC2 means a 2-channel (complex) floating-point array
	//* CV_8UC1 means a 8-bit single chaneel array
	cv::Mat o_mat1(7, 7, CV_32FC2, cv::Scalar(1, 3));
	cout << o_mat1 << endl;

	//* Mat::type and Mat::depth
	cout << "Type is..." <<	o_mat1.type() << endl;
	cout << "Depth is..." << o_mat1.depth() << endl << endl;
	//* verify the depth of CV_32F
	cout << CV_32F << endl;
	cout << CV_32FC1 << endl << endl;

	float arr[3][3] = { { 1.1, 1.2, 1.3 }, { 2.1, 2.2, 2.3 }, { 3.1, 3.2, 3.3} };
	cv::Mat o_matArr = cv::Mat(3, 3, CV_32FC1, arr); //* load the array to Mat
	cv::Mat o_matArrInv = o_matArr.inv();            //* Mat::inv, inverse
	cout << o_matArr << endl;
	cout << o_matArrInv << endl <<endl;


	float foo[2][2] = { {1, 0}, {0, 1} };
	float bar[2][2] = { {99, 99}, {99, 99} };
	cv::Mat o_matFoo = cv::Mat(2, 2, CV_32FC1, foo);
	cv::Mat o_matBar = cv::Mat(2, 2, CV_32FC1, bar);
	cv::Mat o_matFB = o_matFoo * o_matBar;  //* matrix multiplication
	cout << o_matFB << endl;








    return 0;
}

