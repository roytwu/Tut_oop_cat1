//* File name:   main.cpp
//* Programmer:  Roy T Wu
//* Description: Kalman filter implementation

#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Core>             //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>            //* Eigen library: Matrix
#include <Eigen/Geometry>         //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> 
using std::cout; 
using std::endl;
using std::string; 

int main()
{
	//cout << "\n----- Matrix concatenation -----\n";
	cv::Matx66d p0 = cv::Matx66d::eye(); //* state err covariance matx
	cv::Mat h;
	cv::hconcat(cv::Matx33d::all(0), cv::Matx33d::eye(), h);
	cout << "Output of horizontal concatenation: \n" << h << endl << endl;






    return 0;
}

