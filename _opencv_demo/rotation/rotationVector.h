//* File name:   rotationVector.h
//* Developer:   Roy T Wu
//* Description: special class for rotaion vectors                

#pragma once
#ifndef ROTATIONVECTOR
#define ROTATIONVECTOR

#include <opencv2/opencv.hpp> 

class RotVec {
public:
	//* convert rotation vector to OpenCV's quaternion
	cv::Vec4d rotVecToQuat(const cv::Vec3d &);

	//* convert Rodrigues formula to rotation vector
	cv::Vec3d rodriguesToRotVec(const cv::Vec4d &);

};

#endif //ROTATIONVECTOR
