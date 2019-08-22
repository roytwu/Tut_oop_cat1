#pragma once
#ifndef QUATERNION_H
#define QUATERNION_H

#include <opencv2/opencv.hpp>

namespace S3
{
	//* quaternion multiplication
	cv::Vec4d quatMultiplication(const cv::Vec4d &, const cv::Vec4d &);

	//* quaternion multiplication (alternative)
	//* Let q and p be unit quaternion, and p*q = rightToLeft(q) *p 
	cv::Matx44d rightToLeft(const cv::Vec4d &);

	//* quaternion multiplication (matrix version 2)
	//* p*q = quatMultMatx(p)*q
	cv::Matx44d quatMultMatx(const cv::Vec4d &);

	//* quaternion inverse
	cv::Vec4d quatInverse(const cv::Vec4d &);

	//* convert CV quaternion to CV SO(3) 
	cv::Matx33d cvQuatToSO3(const cv::Vec4d &);

	//* -mapping SO(3) to OpenCV's quaternion
	//* @param: rotm   rotation matrix   
	cv::Vec4d SO3ToCVQuat(cv::Matx33d const& rotm);

	//* convert angle-axis representation to quaternionn
	cv::Vec4d rodriguesToQuat(const cv::Vec4d &);

	//* hat map: transform a 3x1 vector to a 3x3 skew-symmetric matrix 
	//*          such that cross(x,y) = hat(x)*y
	cv::Matx33d hat(const cv::Vec3d &);

	//* -vee map 
	//* @param: m   3x3 skew-symmetric matrix
	cv::Vec3d vee(const cv::Matx33d &m);

};



#endif //* QUATERNION_H