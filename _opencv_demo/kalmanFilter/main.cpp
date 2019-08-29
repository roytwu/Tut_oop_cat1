/* *********************************************************
File name:   main.cpp (_kalman)
Programmer:  Roy Wu
Description: sandbox of Kalman filteting implementation
********************************************************* */
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
	unsigned int type = CV_64F;
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

	cout << "\n----- concatenating multiple matrices -----\n";
	double e0[3][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
	double e1[3][3] = { {1,1,1},   {1,1,1},   {1,1,1} };
	double e2[3][2] = { {2,2},     {2,2},     {2,2} };
	double e3[3][1] = { {3},       {3},       {3}  };
	cv::Mat mat_e0 = cv::Mat(3, 4, type, e0);
	cv::Mat mat_e1 = cv::Mat(3, 3, type, e1);
	cv::Mat mat_e2 = cv::Mat(3, 2, type, e2);
	cv::Mat mat_e3 = cv::Mat(3, 1, type, e3);
	std::vector<cv::Mat> matrices{mat_e0, mat_e1, mat_e2, mat_e3};
	cv::Mat e0123;
	cv::hconcat(matrices, e0123);
	cout << e0123 << endl;

	cout << "\n----- Initialize cv::Mat in different ways -----\n";
	double arr_foo[3][6] = { { 1.0, 0., 0., 0., 0., 0. },
	                       	     { 0., -1., 0., 0., 0., 0. },
		                         { 0., 0., -1., 0., 0., 0. } };
	cv::Matx<double, 3, 6> foo3x6 = cv::Mat(3, 6, type, arr_foo);
	cout << foo3x6 << endl;

	//* initialize cv::Mat with all zeros
	cv::Mat m_0_3x1 = cv::Mat::zeros(cv::Size(3,1), type); //* all zeros
	cv::Mat m_1_3x1(cv::Size(3, 1), type, cv::Scalar(1));  //* all ones

	//cout << m_1_3x1 << endl;


    return 0;
}

