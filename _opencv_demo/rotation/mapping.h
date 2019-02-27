//* File name: mapping.h
#pragma once
#ifndef MAPPING
#define MAPPING

#include <Eigen/Core>             //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>            //* Eigen library: Matrix
#include <Eigen/Geometry>         //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> 


class SO3toQuat {
public:

	//cv::cv2eigen(R, eigenM);


private:
	cv::Matx33d R;
	Eigen::MatrixXd eigenM;       //* Eigen library, Dynamic float matrix 
};





#endif //MAPPING