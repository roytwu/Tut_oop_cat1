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


//* ----- ----- convert Euler angles to SO(3) ----- -----
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


//* ----- ----- conver Eigen's quaternion to CV SO(3) ----- -----
cv::Matx33d SO3Mapping::EGQuatToSO3(Eigen::Quaterniond egQ) {
	Eigen::Matrix3d egR;
	cv::Matx33d cvR;
	egR = egQ.toRotationMatrix();
	cv::eigen2cv(egR, cvR);

	return cvR;
}

//* ----- ----- conver CV's custom quaternion to CV SO(3) ----- -----
cv::Matx33d SO3Mapping::CVQuatToSO3(cv::Vec4d &q) {
	double q0 = q(0);
	cv::Vec3d q_vec(q(1), q(2), q(3));

	cv::Matx33d result;
	result = cv::Matx33d::eye() + 2*hat(q_vec)*hat(q_vec) +2*q0*hat(q_vec);
	return result;
}



//* ----- ----- Priting functions ----- -----
void SO3Mapping::printEigenQuat(Eigen::Quaterniond q){
	std::cout << q.w() << std::endl;
	std::cout << q.vec() << std::endl;
}


//* ----- ----- round very small double to zero ----- -----
void SO3Mapping::roundTinyDoubleToZero(cv::Matx33d & cvR) {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (std::abs(cvR(i, j)) < 0.0000001) {
				cvR(i, j) = 0;
			}
		}
	}
}


//* ----- ----- hat map ----- -----
cv::Matx33d SO3Mapping::hat(cv::Vec3d v) {
	double v1 = v(0);
	double v2 = v(1);
	double v3 = v(2);
	cv::Matx33d result(0, -v3, v2, v3, 0, -v1, -v2, v1, 0);
	
	return result;
}