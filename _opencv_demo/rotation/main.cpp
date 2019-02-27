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
	cout << endl << "----- Rodrigues formula -----" << endl;
	//* cv::Rodrigues transform between a rotation matrix to a rotation 
	cv::Matx33d o_xEye33 = cv::Matx33d::eye();        //* identity matrix
	cv::Matx33d mx_xPi(1, 0, 0, 0, -1, 0, 0, 0, -1);  //* rotate pi along x-axis
	cv::Matx31d rv_xPi;
	cv::Rodrigues(mx_xPi, rv_xPi);
	cout << rv_xPi << endl;

    return 0;
}