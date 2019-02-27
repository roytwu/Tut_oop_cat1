//* File name:   main.cpp
//* Programmer:  Roy T Wu
//* Description: Demo aoubt 3D rotations in OpenCV

#include <iostream>
#include <string>
#include "mapping.h"

using std::cout; 
using std::endl;
using std::string; 


int main()
{
	cv::Matx33d rm_Eye33 = cv::Matx33d::eye();        //* identity matrix
	cv::Matx33d rm_x_Pi(1, 0, 0, 0, -1, 0, 0, 0, -1); //* rotate pi along x-axis
	
	SO3Mapping o_foo;
	cv::Vec3d v_euler(0.5, 1.0, 0.7);  
	cv::Matx33d rm_toto = o_foo.EulerToSO3(v_euler); //* create arbitrary rotation matrix
	cout << rm_toto << endl << endl;
	cout << "This shall output identity matrix... " << endl;
	cout << rm_toto* rm_toto.t() << endl;
	

	Eigen::Quaterniond eigenQ = o_foo.SO3ToEigenQuat(rm_x_Pi);
	o_foo.printEigenQuat(eigenQ);

	cv::Vec4d v_quat = o_foo.SO3ToCVQuat(rm_x_Pi);
	cout << v_quat << endl;
	

	return 0;
}