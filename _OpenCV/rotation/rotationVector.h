//* File name:   rotationVector.h
//* Developer:   Roy T Wu
//* Description: class for rotaion vectors. Rotation vector (3 parameters) is a 
//*              special form of Rodrigues formula (4 parameters), which is heavily used in OpenCV

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
