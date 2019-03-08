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
	double pi = 3.14159265359;
	cv::Matx33d rm_eye33 = cv::Matx33d::eye();        //* identity matrix
	cv::Matx33d rm_x_Pi(1, 0, 0, 0, -1, 0, 0, 0, -1); //* rotate pi along x-axis
	
	SO3Mapping o_mapping;

	//* Step 1, start from Euler angle, conver to SO(3)
	cv::Vec3d v_euler(0.5, pi, 0.7);  
	cv::Matx33d rm_euler = o_mapping.EulerToSO3(v_euler); //* create arbitrary rotation matrix
	cout << rm_euler << endl << endl;

	//* verify the mapping is legit
	cout << "(Rotation matrix check) shall output identity matrix... " << endl;
	cv::Matx33d  result = rm_euler* rm_euler.t();
	o_mapping.roundTinyDoubleToZero(result);
	cout << result << endl << endl;
	

	//* Step 2, map SO(3) to Eigen quaternion and OpenCV quaternion, respectively
	Eigen::Quaterniond eigenQ = o_mapping.SO3ToEigenQuat(rm_euler);
	o_mapping.printEigenQuat(eigenQ);
	cout << endl;
	cv::Vec4d v_quat = o_mapping.SO3ToCVQuat(rm_euler);
	cout << v_quat << endl << endl;

	//* Step 3, convert both quaternions back to SO(3)
	cv::Matx33d rm_resultA;
	cv::Matx33d rm_resultB;
	rm_resultA = o_mapping.EGQuatToSO3(eigenQ);
	cout << rm_resultA -rm_euler << endl;


	return 0;
}