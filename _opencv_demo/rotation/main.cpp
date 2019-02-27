//* File name:   main.cpp
//* Programmer:  Roy T Wu
//* Description: Demo aoubt 3D rotations in OpenCV

#include <iostream>
#include <string>
//#include <Eigen/Core>             //* this needs to added before <opencv2/core/eigen.hpp>
//#include <Eigen/Dense>            //* Eigen library: Matrix
//#include <Eigen/Geometry>         //* Eigen library: quaternion
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/eigen.hpp> 
#include "mapping.h"

using std::cout; 
using std::endl;
using std::string; 


int main()
{
	cv::Matx33d mx_Eye33 = cv::Matx33d::eye();        //* identity matrix
	cv::Matx33d mx_X_Pi(1, 0, 0, 0, -1, 0, 0, 0, -1);  //* rotate pi along x-axis
	
	SO3Mapping o_foo;
	Eigen::Quaterniond eigenQ = o_foo.SO3ToEigenQuat(mx_X_Pi);
	o_foo.printEigenQuat(eigenQ);

	cv::Matx31d rv_X_Pi;
	cv::Rodrigues(mx_X_Pi, rv_X_Pi);
	cv::Vec4d v_quat = o_foo.RotationVectorToQuat(rv_X_Pi);
	cout << v_quat << endl;

	return 0;
}