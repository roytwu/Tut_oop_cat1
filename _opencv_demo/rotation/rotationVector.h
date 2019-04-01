//* File name: rotationVector.h
#pragma once
#ifndef ROTATIONVECTOR
#define ROTATIONVECTOR

#include <opencv2/opencv.hpp> 

class RotVec {
public:
	//* convert rotation vector to OpenCV's quaternion
	cv::Vec4d rotVecToQuat(cv::Vec3d &);

	//* convert Rodrigues formula to rotation vector
	//cv::Vec3d rodriguesToRotVec(cv::Vec4d &);

};




#endif //ROTATIONVECTOR
