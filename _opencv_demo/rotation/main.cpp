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

	////* ===== ===== hat map and vee map ===== =====
	//cout << "\n----- verify hat() and vee() -----\n";
	//cv::Vec3d vec_foo(0.3, -1.5, 0.7);
	//auto mat_foo = o_mapping.hat(vec_foo);
	//auto vec_foo2 = o_mapping.vee(mat_foo);
	//cout << mat_foo << endl;
	//cout << vec_foo2 << endl;

	//* ---Step 1, start from Euler angle, conver to SO(3)
	cv::Vec3d v_toto(0.5, CV_PI, 0.7);                  //* CV_PI is the OpenCV defined constant
	cv::Matx33d rm_toto = o_mapping.EulerToSO3(v_toto); //* create arbitrary rotation matrix
	//cout << rm_toto << endl;

	////* verify the mapping is legit
	//cout << "(Rotation matrix check) shall output identity matrix... \n";
	//cv::Matx33d  result = rm_toto* rm_toto.t();
	//o_mapping.roundTinyDoubleToZero(result);
	//cout << result << endl;
	
	//* ---Step 2,  map SO(3) to Eigen quaternion and custom CV quaternion respectively
	cout << "\n----- Eigen vs CV  -----\n";
	cout << "*** quaternion from Eigen: \n";
	Eigen::Quaterniond eigenQ = o_mapping.SO3ToEigenQuat(rm_toto);
	o_mapping.printEigenQuat(eigenQ);
	
	cout << "\n*** quaternion in CV: \n";
	cv::Vec4d v_quat = o_mapping.SO3ToCVQuat(rm_toto);
	cout << v_quat << endl;

	cout << "\n*** quaternion in CV (via Rodrigues()): \n";
	cv::Vec3d rv_toto;
	cv::Rodrigues(rm_toto, rv_toto);
	cv::Vec4d q_toto = o_RV.rotVecToQuat(rv_toto);
	cout << q_toto << endl;

	//* ---Step 3, convert both quaternions back to SO(3)
	cv::Matx33d so3_A, so3_B;
	so3_A = o_mapping.EGQuatToSO3(eigenQ);  //* convert from Eigen
	so3_B = o_mapping.CVQuatToSO3(v_quat);  //* convert from CV
	cout << "\nThis shall output identiy.. \n";
	cout << so3_A*so3_B.t() << endl;  


	//* ===== ===== Rotation Vector ===== =====
	cout << "\n----- testing cv::Rodrigues() -----\n";
	cv::Vec3d euler1(0, -CV_PI/2, 0);
	cv::Matx33d rm1 = o_mapping.EulerToSO3(euler1);
	cout << rm1 << endl;

	cv::Mat rv;
	cv::Rodrigues(rm1, rv);  //* build-in function in CV
	cout << rv << endl;

	
	cv::Vec4d rod = o_mapping.so3ToRodrigues(rm1); //* rotation matrix to Rodrigues formula
	cv::Vec3d rv_1 = o_RV.rodriguesToRotVec(rod);  //* Rodrigues formula to rotation vector
	cout << rv_1 << endl;


	//* ===== ===== unit quaternion to SO(3) ===== =====
	cout << "\n----- S(3) to SO(3) -----\n";
	cv::Vec4d eyeQ(1.0, 0, 0, 0);
	auto eyeSO3 = o_mapping.CVQuatToSO3(eyeQ);
	cout << eyeSO3 << endl;



	return 0;
}