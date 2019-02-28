//* File name:   main.cpp
//* Programmer:  Roy T Wu
//* Description: Demonstrate mpping SO(3) to quaternion with OpenCV and Eigen
//*              

#include <iostream>
#include <string>
#include "mapping.h"

using std::cout; 
using std::endl;
using std::string; 


int main()
{
	cv::Matx33d rm_eye33 = cv::Matx33d::eye();        //* identity matrix
	cv::Matx33d rm_x_Pi(1, 0, 0, 0, -1, 0, 0, 0, -1); //* rotate pi along x-axis
	
	SO3Mapping o_mapping;

	cv::Vec3d v_euler(0.5, 1.0, 0.7);  
	cv::Matx33d rm_euler = o_mapping.EulerToSO3(v_euler); //* create arbitrary rotation matrix
	cout << rm_euler << endl << endl;
	cout << "(Rotation matrix check) shall output identity matrix... " << endl;
	cout << rm_euler* rm_euler.t() << endl << endl;
	

	Eigen::Quaterniond eigenQ = o_mapping.SO3ToEigenQuat(rm_euler);
	o_mapping.printEigenQuat(eigenQ);
	cout << endl;

	cv::Vec4d v_quat = o_mapping.SO3ToCVQuat(rm_euler);
	cout << v_quat << endl;
	

	return 0;
}