//* File name:   main.cpp
//* Developer:   Roy T Wu
//* Description: Demonstrate mpping SO(3) to quaternion with OpenCV and Eigen        

#include <iostream>
#include <string>
#include "mapping.h"
#include "rotationVector.h"

using std::cout; 
using std::endl;
using std::string; 

int main()
{
	cv::Matx33d rm_eye = cv::Matx33d::eye();          //* identity matrix
	cv::Matx33d rm_x_Pi(1, 0, 0, 0, -1, 0, 0, 0, -1); //* rotate pi along x-axis
	SO3Mapping o_mapping;
	RotVec     o_RV;

	//* ---Step 1, start from Euler angle, conver to SO(3)
	cv::Vec3d v_toto(0.5, CV_PI, 0.7);                  //* CV_PI is the OpenCV defined constant
	cv::Matx33d rm_toto = o_mapping.EulerToSO3(v_toto); //* create arbitrary rotation matrix
	//cout << rm_toto << endl;


	//* ---Step 2,  map SO(3) to Eigen quaternion and custom CV quaternion respectively
	cout << "\n----- Eigen vs CV  -----\n";
	cout << "*** quaternion from Eigen: \n";
	Eigen::Quaterniond eigenQ = o_mapping.SO3ToEigenQuat(rm_toto);
	o_mapping.printEigenQuat(eigenQ);
	
	cout << "\n*** quaternion in CV: \n";
	cv::Vec4d v_quat = o_mapping.SO3ToCVQuat(rm_toto);
	cout << v_quat << endl;



	//* ===== ===== unit quaternion to SO(3) ===== =====
	cout << "\n----- S(3) to SO(3) -----\n";
	cv::Vec4d eyeQ(1.0, 0, 0, 0);
	auto eyeSO3 = o_mapping.CVQuatToSO3(eyeQ);
	cout << eyeSO3 << endl;



	return 0;
}