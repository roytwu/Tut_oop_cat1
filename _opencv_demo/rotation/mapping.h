//* File name: mapping.h
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
	//* mapping SO(3) to Eigen's quaternion (Eigen::Quaternion<double>)
	Eigen::Quaterniond SO3ToEigenQuat(cv::Matx33d); 

	//* mapping SO(3) to OpenCV's quaternion
	cv::Vec4d SO3ToCVQuat(cv::Matx33d);             

	//* mapping rotation vector to OpenCV's quaternion
	cv::Vec4d RotationVectorToQuat(cv::Matx31d rv); 

	//* mapping Euler angles to SO(3)
	cv::Matx33d EulerToSO3(cv::Vec3d);

	//* print out Eigen's quaternion
	void printEigenQuat(Eigen::Quaterniond);
	

private:
	cv::Matx33d R;
	Eigen::MatrixXd eigenM;       //* Eigen library, Dynamic float matrix 
};





#endif //MAPPING