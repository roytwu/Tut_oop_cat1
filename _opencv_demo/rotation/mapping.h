//* File name:   mapping.h
//* Developer:   Roy T Wu
//* Description: member functions of SO3Mapping class can be used to 
//*              map SO(3) to other representations and vice versa      

#pragma once
#ifndef MAPPING
#define MAPPING

#include <cmath>
#include <vector>
#include <Eigen/Core>             //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>            //* Eigen library: Matrix
#include <Eigen/Geometry>         //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> 


class SO3Mapping {
public:
	//* ----- ----- SO(3) mapping to other representaitons ----- -----
	//* mapping SO(3) to Eigen's quaternion (Eigen::Quaternion<double>)
	Eigen::Quaterniond SO3ToEigenQuat(cv::Matx33d); 

	//* mapping SO(3) to OpenCV's quaternion
	cv::Vec4d SO3ToCVQuat(cv::Matx33d);    

	//* convert SO(3) to Rodrigues formula
	cv::Vec4d so3ToRodrigues(cv::Matx33d &);

	//* ----- ----- other representaitons mapping to SO(3) ----- -----
	//* convert Euler angles to SO(3)
	cv::Matx33d EulerToSO3(cv::Vec3d);

	//* convert Eigen's quaternion to CV SO(3)
	cv::Matx33d EGQuatToSO3(Eigen::Quaterniond);

	//* convert CV's quaternion to CV SO(3)
	cv::Matx33d CVQuatToSO3(cv::Vec4d &);


	//* ----- ----- Not-important funcitons ----- -----
	//* print out Eigen's quaternion
	void printEigenQuat(Eigen::Quaterniond);

	//* round very small double to zero
	void roundTinyDoubleToZero(cv::Matx33d &);
	

//private:
	//* ----- ----- hat map and vee map ----- -----
	//* hat map
	cv::Matx33d hat(const cv::Vec3d &) const;

	//*vee map 
	cv::Vec3d vee(const cv::Matx33d &) const;
};





#endif //MAPPING