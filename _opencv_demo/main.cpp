//* File name:   main.cpp
//* Programmer:  Roy T Wu
//* Description: Demo aoubt matrix operations in OpenCV

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
	//cv::Mat test(100, 100, CV_8U, cv::Scalar::all(150));
	//cv::imshow("test_window", test);
	//cv::waitKey(0); //wait infinitely until any keystroke in the window

	//* make a 5x5 complex matrix filled with i+3j
	//* CV_32FC2 means a 2-channel (complex) floating-point array
	//* CV_8UC1 means a 8-bit single chaneel array
	cv::Mat o_mat1(5, 5, CV_32FC2, cv::Scalar(1, 3));
	cout << o_mat1 << endl << endl;

	//* conver Mat reference to Mat_ reference
	cv::Mat_<float>& o_matA = (cv::Mat_<float>&)o_mat1;
	cout << o_matA << endl;


	//* Mat::type and Mat::depth
	cout << "Type is..." <<	o_mat1.type() << endl;
	cout << "Depth is..." << o_mat1.depth() << endl;
	//* verify the depth of CV_32F
	cout << CV_32F << endl;
	cout << CV_32FC1 << endl;

	cout << endl << "----- matrix multiplacation and transpose -----" << endl;
	float foo[2][2] = { {1, 0}, {0, 1} };
	float bar[2][2] = { {22, 33}, {77, 88} };
	cv::Mat o_matFoo = cv::Mat(2, 2, CV_32FC1, foo);
	cv::Mat o_matBar = cv::Mat(2, 2, CV_32FC1, bar);
	cv::Mat o_matFB = o_matFoo * o_matBar;  //* matrix multiplication
	cv::Mat o_matToto = o_matBar.t();       //* matrix transpose
	cout << o_matFB << endl << o_matToto << endl;

	//* Matx are template class whose size are known at comilation time
	cout << endl << "----- class Matx -----" << endl;
	double arr[3][3] = { { 1.1, 1.2, 1.3 },{ 2.1, 2.2, 2.3 },{ 3.1, 3.2, 3.3 } };

	//* Matx33d represents 3x3 matrix of double type
	//* for double type array, use CV_64
	cv::Matx33d o_matArr = cv::Mat(3, 3, CV_64FC1, arr); //* load the array to Matx33d
	cv::Matx33d o_matArrInv = o_matArr.inv();            //* matrix inverse
	cout << o_matArr << endl;
	cout << o_matArrInv << endl << endl;

	//* cv::Matx with 4 by 4 float
	cv::Matx44f o_xMF(11, 12, 13, 14,
		21, 22, 23, 24,
		31, 32, 33, 34,
		41, 42, 43, 44);
	cv::Matx44f o_xEye44 = cv::Matx44f::eye(); //* identity matrix	 
    cout << o_xMF << endl;
	cout << o_xMF.t() << endl;                 //* matrix transpose
	//cout << o_xMF*o_xEye44 << endl << endl;    //* matrix multiplacation 

    //* access columns in Matx
	cout << endl << "----- access columns in Matx -----" << endl;
	cout << o_xMF.col(0) << endl;                //* c-out 1st column
	cv::Matx41f o_mat2 = o_xMF.col(3);           //* 4th column, by default its a 4 by 1 matrix 
	cv::Mat     o_mat3 = cv::Mat(o_xMF.col(3));  //* 4th column, change to cv::Mat format
	cout << o_mat2 << endl;
	cout << o_mat3 << endl << endl;

	// colRange() and rowRange()
	cv::Mat o_mat4 = cv::Mat(o_xMF).colRange(0,3);  //* 1st to 3rd column, change to cv::Mat format
	cv::Mat o_mat5 = o_mat4.rowRange(0,3);         
	cout << o_mat5 << endl << endl;
	

	//* convert cv::Mat to std::vector
    std::vector<double> v_4thCol;
	v_4thCol.assign(o_mat3.begin<float>(), o_mat3.end<float>());
	for (auto i : v_4thCol) {
		cout << i << " ";
	}
	cout << endl;

	cout << endl << "----- conversion between Eigen matrix and OpenCV matrix -----" << endl;
	Eigen::MatrixXf em;       //* Eigen library, Dynamic float matrix 
	cv::cv2eigen(o_xMF, em);
	cout << em << endl << endl;

	Eigen::Quaternion<double> eyeQ = Eigen::Quaterniond::Identity();
	Eigen::Matrix3d R_eye;  //* 3x3 matrix of double (Eigen)
	cv::Matx33d cvR;        //* 3x3 matrix of double (OpenCV) 

	R_eye = eyeQ.toRotationMatrix(); //* convert quaternion to rotation matrix 
	cv::eigen2cv(R_eye, cvR);
	cout << cvR << endl;

    return 0;
}

