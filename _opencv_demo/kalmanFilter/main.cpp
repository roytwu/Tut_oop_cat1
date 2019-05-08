//* File name:   main.cpp
//* Programmer:  Roy T Wu
//* Description: building blocks for Kalman filter 

#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Core>              //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>             //* Eigen library: Matrix
#include <Eigen/Geometry>          //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> 
using std::cout; 
using std::endl;
using std::string; 



//void findMatrixSize(cv::Mat_<double> & m) 
void findMatrixSize(cv::Mat & m)
{
	//* approach #1 - using cv::Size
	cv::Size s = m.size();
	int r1 = s.height;
	int c1 = s.width;

	//* approach #2 - without cv::Size
	int r2 = m.rows;
	int c2 = m.cols;

	cout << "(" << r1 << ", " << c1 << ")" << endl;
	cout << "(" << r2 << ", " << c2 << ")" << endl;
}


int main()
{
	//cout << "\n----- H -----\n";
	cv::Matx66d p0 = cv::Matx66d::eye(); //* state err covariance matx
	cv::Mat h;
	cv::hconcat(cv::Matx33d::all(0), cv::Matx33d::eye(), h);
	cout << "Observation matrix H (3x6):  \n" << h << endl << endl;


	//cout << "\n----- F -----\n";
	double dt = 0.001;
	cv::Mat dummyF1, dummyF2;
	cv::Matx66d f66;
	cv::Matx33d f33 = dt*cv::Matx33d::eye();
	cv::hconcat(cv::Matx33d::eye(), f33, dummyF1);
	cv::hconcat(cv::Matx33d::all(0), cv::Matx33d::eye(), dummyF2);
	cv::vconcat(dummyF1, dummyF2, f66);
	cout << "system state matrix F (6x6):  \n" << f66 << endl << endl;

	//* find matrix size, need to convert from Matx to Mat_ or Mat first
	//findMatrixSize(cv::Mat_<double>(f66));
	findMatrixSize(cv::Mat(f66));



    return 0;
}

