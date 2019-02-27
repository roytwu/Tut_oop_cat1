//* File name:   main.cpp
//* Programmer:  Roy T Wu
//* Description: Demo aoubt 3D rotations in OpenCV

#include <iostream>
#include <vector>
#include <string>
#include "mapping.h"

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

	cv::Matx33d R = cv::Matx33d::eye();
	Eigen::MatrixXd eigenM;       //* Eigen library, Dynamic float matrix 
	cv::cv2eigen(R, eigenM);
    return 0;
}