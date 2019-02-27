#include <iostream>
#include "mapping.h"

Eigen::Quaterniond SO3Mapping::SO3ToEigenQuat(cv::Matx33d cvR) {
	Eigen::Matrix3d eigenR;
	cv::cv2eigen(cvR, eigenR);

	Eigen::Quaterniond eigenQ;
	eigenQ = eigenR; //* convert SO(3) to quaternion

	return eigenQ;
}


cv::Vec4d SO3Mapping::RotationVectorToQuat(cv::Matx31d rv) {
	//cv::Matx33d r;
	cv::Vec4d quat;
	double rv_x = rv(0, 0);  //*access element from 0-th row, 0-th cloumn
	double rv_y = rv(1, 0);  //*access element from 1-th row, 0-th cloumn
	double rv_z = rv(2, 0);  //*access element from 2-th row, 0-th cloumn
	double rv_norm = sqrt(pow(rv_x, 2) + pow(rv_y, 2) + pow(rv_z, 2));
	quat(0) = cos(rv_norm/2);
	quat(1) = sin(rv_norm/2) * rv_x / rv_norm;
	quat(2) = sin(rv_norm/2) * rv_y / rv_norm;
	quat(3) = sin(rv_norm/2) * rv_z / rv_norm;

	return quat;
}


//* ----- ----- Priting functions ----- -----
void SO3Mapping::printEigenQuat(Eigen::Quaterniond q){
	std::cout << q.w() << std::endl;
	std::cout << q.vec() << std::endl;
}