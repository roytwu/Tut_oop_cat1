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

	output1 = S3::quatMultiplication(quat_toto, quat_tata);
	cout << output1 << endl;


	output2 = S3::rightToLeft(quat_tata) * quat_toto;
	//output2 = cv::Mat(S3::rightToLeft(quat_tata)) * cv::Mat(quat_toto);
	cout << output2 << endl;



	////* ===== ===== unit quaternion to SO(3) ===== =====
	//cout << "\n----- S(3) to SO(3) -----\n";
	//cv::Vec4d eyeQ(1.0, 0, 0, 0);
	//auto eyeSO3 = o_mapping.CVQuatToSO3(eyeQ);
	//cout << eyeSO3 << endl;

	return 0;
}