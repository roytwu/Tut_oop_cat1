//* File name:   main.cpp
//* Developer:   Roy T Wu
//* Description: Demonstrate quaternion operation      

#include <iostream>
#include <string>
#include "mapping.h"
#include "quaternion.h"

using std::cout; 
using std::endl;
using std::string; 

int main()
{
	cv::Matx33d eye33 = cv::Matx33d::eye();          //* identity matrix
	cv::Matx33d rm_x_Pi(1, 0, 0, 0, -1, 0, 0, 0, -1); //* rotate pi along x-axis
	SO3Mapping o_mapping;

	//* ---Step 1, start from Euler angle, conver to SO(3)
	cv::Vec3d v_toto(0.33, CV_PI, 0.6);  
	cv::Vec3d v_tata(CV_PI, 0.1, 0.25);
	cv::Matx33d rm_toto = o_mapping.EulerToSO3(v_toto); 
	cv::Matx33d rm_tata = o_mapping.EulerToSO3(v_tata);
	
	//* ---Step 2,  map SO(3) to  quaternion 
	cout << "\n*** quaternion in CV: \n";
	cv::Vec4d quat_toto = o_mapping.SO3ToCVQuat(rm_toto);
	cv::Vec4d quat_tata = o_mapping.SO3ToCVQuat(rm_tata);
	
	cv::Vec4d output1;
	cv::Vec4d output2;
	cv::Vec4d output3;

	output1 = S3::quatMultiplication(quat_toto, quat_tata);
	cout << output1 << endl;

	output2 = S3::rightToLeft(quat_tata) * quat_toto;
	//output2 = cv::Mat(S3::rightToLeft(quat_tata)) * cv::Mat(quat_toto);
	cout << output2 << endl;

	output3 = S3::quatMultMatx(quat_toto) * quat_tata;
	cout << output3 << endl;

	////* ===== ===== unit quaternion to SO(3) ===== =====
	//cout << "\n----- S(3) to SO(3) -----\n";
	//cv::Vec4d eyeQ(1.0, 0, 0, 0);
	//auto eyeSO3 = o_mapping.CVQuatToSO3(eyeQ);
	//cout << eyeSO3 << endl;

	//* ===== ===== testing ===== =====
	cout << "\n*** real case testing: \n";
	double e_06 = 0.000001;
	cv::Vec4d q1(0.98536, -0.138276, -0.0842242, -0.0534023);
	cv::Vec4d dq1(1, -1.39893*e_06, -1.06585*e_06, -1.93185*e_06);
	//cv::Vec4d q1(0.985345, -0.13834, -0.0842713, -0.0534294);
	//cv::Vec4d dq1(1, -4.39663*e_06, -2.86447*e_06, -0.666156*e_06);
	cv::Vec4d result;
	result = S3::quatMultiplication(q1, dq1);
	cout << result << endl;


	return 0;
}