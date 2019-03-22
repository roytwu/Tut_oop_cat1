//* File name:   main.cpp
//* Programmer:  Roy T Wu
//* Description: Demonstrate mpping SO(3) to quaternion with OpenCV and Eigen        

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

	//* ===== ===== Eigen version ===== =====
	//* ---Step 1, start from Euler angle, conver to SO(3)
	cv::Vec3d v_euler(0.5, CV_PI, 0.7);   //* CV_PI is the OpenCV defined constant
	cv::Matx33d rm_euler = o_mapping.EulerToSO3(v_euler); //* create arbitrary rotation matrix
	cout << rm_euler << endl << endl;

	//* verify the mapping is legit
	cout << "(Rotation matrix check) shall output identity matrix... \n";
	cv::Matx33d  result = rm_euler* rm_euler.t();
	o_mapping.roundTinyDoubleToZero(result);
	cout << result << endl << endl;
	
	//* ---Step 2,  map SO(3) to Eigen quaternion and OpenCV quaternion, respectively
	Eigen::Quaterniond eigenQ = o_mapping.SO3ToEigenQuat(rm_euler);
	o_mapping.printEigenQuat(eigenQ);
	cout << endl;
	cv::Vec4d v_quat = o_mapping.SO3ToCVQuat(rm_euler);
	cout << v_quat << endl << endl;

	//* ---Step 3, convert both quaternions back to SO(3)
	cv::Matx33d so3_A, so3_B;
	so3_A = o_mapping.EGQuatToSO3(eigenQ);  
	cout << so3_A << endl;

	//* OpenCV
	so3_B = o_mapping.CVQuatToSO3(v_quat); 
	cout << so3_B << endl;
	cout << "This shall output identiy.. \n" << so3_A*so3_B.t() << endl;  //* verfy the result


	//* ===== ===== OpenCV version ===== =====
	//* ---Step 1, creating SO(3) from Euler angle
	cv::Vec3d euler1(0, CV_PI, 0);
	cv::Matx33d rm1 = o_mapping.EulerToSO3(euler1);
	
	//* ---Step 2, mapping SO(3) to S(3) and then performing reverse map to  
	cv::Vec4d quat1 = o_mapping.SO3ToCVQuat(rm1);
	cv::Matx33d rm11 = o_mapping.CVQuatToSO3(quat1);
	cout << rm1*rm11.t() << endl;

	return 0;
}