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
	Eigen::Quaterniond SO3ToEigenQuat(cv::Matx33d);
	cv::Vec4d SO3ToCVQuat(cv::Matx33d);
	cv::Vec4d RotationVectorToQuat(cv::Matx31d rv);
	cv::Matx33d EulerToSO3(cv::Vec3d);

	void printEigenQuat(Eigen::Quaterniond);
	

private:
	cv::Matx33d R;
	Eigen::MatrixXd eigenM;       //* Eigen library, Dynamic float matrix 
};





#endif //MAPPING