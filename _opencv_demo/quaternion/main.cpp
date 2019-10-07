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

	//* ### start from Euler angle, convert to SO(3)
	cv::Vec3d v_toto(0, CV_PI, 0.5*CV_PI);  
	cv::Vec3d v_tata(CV_PI, 0., 0.0);
	cv::Matx33d rm_toto = o_mapping.EulerToSO3(v_toto); 
	cv::Matx33d rm_tata = o_mapping.EulerToSO3(v_tata);
    cout << "rm_toto is ...\n" << rm_toto << endl;
    cout << "rm_tata is ...\n" << rm_tata << endl;

    //* ### SO(3) <---> Rotation vector
    cv::Vec3d rotVec_toto;
    cv::Vec3d rotVec_tata;
    cv::Rodrigues(rm_toto, rotVec_toto);
    cv::Rodrigues(rm_tata, rotVec_tata);
    cout << "\nrotVec_toto (from SO(3)) is ...\n" << rotVec_toto << endl;
    cout << "\nrotVec_tata (from SO(3)) is ...\n" << rotVec_tata << endl;

	//* ### SO(3) <---> quaternion 
	cout << "\n*** quaternion in CV: \n";
	cv::Vec4d quat_toto = S3::SO3ToCVQuat(rm_toto);
	cv::Vec4d quat_tata = S3::SO3ToCVQuat(rm_tata);
    cout << "\nquat_toto (from SO(3)) is ...\n" << quat_toto << endl;
    cout << "\nquat_tata (from SO(3)) is ...\n" << quat_tata << endl;
	
    //* ### quaternion operation
	cv::Vec4d output1;
	cv::Vec4d output2;
	cv::Vec4d output3;

	output1 = S3::quatMultiplication(quat_toto, quat_tata);
	cout << "\nquatMultiplication ...\n"<< output1 << endl;

	output2 = S3::rightToLeft(quat_tata) * quat_toto;
	//output2 = cv::Mat(S3::rightToLeft(quat_tata)) * cv::Mat(quat_toto);
	cout << output2 << endl;

	output3 = S3::quatMultMatx(quat_toto) * quat_tata;
	cout << output3 << endl;



    //* ### SO(3) <---> angle axis 
    cv::Vec4d rod_toto = S3::SO3ToRodrigues(rm_toto);
    cout << "\nrod_toto (from SO(3)) is ...\n" << rod_toto << endl;
    cv::Vec4d rod_tata = S3::SO3ToRodrigues(rm_tata);
    cout << "\nrod_tata (from SO(3)) is ...\n" << rod_tata << endl;

    //cv::Matx33d rm_toto2 = S3::rodriguesToSO3(rod_toto);
    //cout << "\nrm_toto2 (from Rodrigues) is ...\n" << rm_toto2 << endl;
    //cv::Matx33d rm_tata2 = S3::rodriguesToSO3(rod_tata);
    //cout << "\nrm_tata2 (from Rodrigues) is ...\n" << rm_tata2 << endl;

    ////* ### quaternion <---> angle axis
    //cv::Vec4d rod_toto2 = S3::quatToRodrigues(quat_toto);
    //cout << "\nrod_toto2 (from quat) is ...\n" << rod_toto2 << endl;

    //cv::Vec4d rod_tata2 = S3::quatToRodrigues(quat_tata);
    //cout << "\nrod_tata2 (from quat) is ...\n" << rod_tata2 << endl;

    //cv::Vec4d quat_toto2 = S3::rodriguesToQuat(rod_toto2);
    //cout << "\nquat_toto2 (from Rodrigues) is ...\n" << quat_toto2 << endl;
    //cv::Vec4d quat_tata2 = S3::rodriguesToQuat(rod_tata2);
    //cout << "\nquat_tata2 (from Rodrigues) is ...\n" << quat_tata2 << endl;



	return 0;
}