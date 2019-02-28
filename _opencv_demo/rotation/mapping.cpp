#include <iostream>
#include "mapping.h"

Eigen::Quaterniond SO3Mapping::SO3ToEigenQuat(cv::Matx33d cvR) {
	Eigen::Matrix3d eigenR;
	cv::cv2eigen(cvR, eigenR); //* convert from OpenCV SO(3) to Eigen SO(3)

	Eigen::Quaterniond eigenQ;
	eigenQ = eigenR;           //* convert  Eigen SO(3) to Eigen quaternion
	return eigenQ;
}


cv::Vec4d SO3Mapping::SO3ToCVQuat(cv::Matx33d cvR) {
	cv::Vec3d rot_vec;
	cv::Vec4d quat;
	cv::Rodrigues(cvR, rot_vec);  //* map CV SO(3) to CV rotation vector

	double rv_x = rot_vec(0);  
	double rv_y = rot_vec(1);
	double rv_z = rot_vec(2); 
	double rv_norm = sqrt(pow(rv_x, 2) + pow(rv_y, 2) + pow(rv_z, 2));

	//* convert rotation vector to quaternion
	quat(0) = cos(rv_norm / 2);
	quat(1) = sin(rv_norm / 2) * rv_x / rv_norm;
	quat(2) = sin(rv_norm / 2) * rv_y / rv_norm;
	quat(3) = sin(rv_norm / 2) * rv_z / rv_norm;
	return quat;
}


cv::Vec4d SO3Mapping::RotationVectorToQuat(cv::Matx31d rv) {
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


cv::Matx33d SO3Mapping::EulerToSO3(cv::Vec3d euler) {
	double roll  = euler(0);
	double pitch = euler(1);
	double yaw   = euler(2);

	Eigen::AngleAxisd R_roll(roll, Eigen::Vector3d::UnitX());
	Eigen::AngleAxisd R_pitch(pitch, Eigen::Vector3d::UnitY());
	Eigen::AngleAxisd R_yaw(yaw, Eigen::Vector3d::UnitZ());

	Eigen::Matrix3d R_euler = (R_roll*R_pitch*R_yaw).matrix();
	cv::Matx33d cvR;
	cv::eigen2cv(R_euler, cvR);
	return cvR;
}

cv::Matx33d SO3Mapping::EGQuatToSO3(Eigen::Quaterniond egQ) {
	Eigen::Matrix3d egR;
	cv::Matx33d cvR;
	egR = egQ.toRotationMatrix();
	cv::eigen2cv(egR, cvR);

	return cvR;
}


//* ----- ----- Priting functions ----- -----
void SO3Mapping::printEigenQuat(Eigen::Quaterniond q){
	std::cout << q.w() << std::endl;
	std::cout << q.vec() << std::endl;
}