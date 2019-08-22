//* File name:   mapping.cpp
//* Developer:   Roy T Wu

#include <iostream>
#include "mapping.h"

//* ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
//* Mapping SO(3) to other representations
//* ===== ===== ===== ===== ===== ===== ===== ===== ===== =====

//* -mapping SO(3) to Eigen's quaternion (Eigen::Quaternion<double>)
//* @param: cvR   rotation matrix   
Eigen::Quaterniond SO3Mapping::SO3ToEigenQuat(cv::Matx33d cvR) {
	Eigen::Matrix3d eigenR;
	cv::cv2eigen(cvR, eigenR); //* convert from OpenCV SO(3) to Eigen SO(3)

	Eigen::Quaterniond eigenQ;
	eigenQ = eigenR;           //* convert  Eigen SO(3) to Eigen quaternion
	return eigenQ;
}

//* -mapping SO(3) to OpenCV's quaternion
//* @param: rotm   rotation matrix   
cv::Vec4d SO3Mapping::SO3ToCVQuat(cv::Matx33d rotm) {
	double tr = cv::trace(rotm);
	double q0 = sqrt(tr + 1.0) / 2;    //* ambiguity
	//double q0 = -sqrt(tr + 1.0) / 2; //* ambiguity
	
	cv::Vec3d dummy = vee(rotm - rotm.t());
	dummy = dummy / (4 * q0);

	cv::Vec4d q(q0, dummy(0), dummy(1), dummy(2));
	return q;
}


//* -convert SO(3) to Rodrigues formula (equivalent to cv::Rodrigues())
//* @param: rotm   rotation matrix  
cv::Vec4d SO3Mapping::so3ToRodrigues(cv::Matx33d &rotm) {
	double tr = cv::trace(rotm);
	double theta = std::acos((tr - 1) / 2);
	if (theta == 0) {
		cv::Vec4d zeros(0, 1, 0, 0);  //* null rotation
		return zeros;
	}

	cv::Matx33d dummy = (1 / (2 * sin(theta)))*(rotm - rotm.t());
	cv::Vec3d v = vee(dummy);

	cv::Vec4d result(theta, v(0), v(1), v(2));
	return result;
}


//* -convert Euler angles to SO(3) 
//* @param: euler   Euler angles in terms of 3x1 vector    
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


//* ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
//* Mapping other representations to SO(3)
//* ===== ===== ===== ===== ===== ===== ===== ===== ===== =====

//* -conver Eigen's quaternion to CV SO(3) 
//* @param: egQ   Eigen quaternion 
cv::Matx33d SO3Mapping::EGQuatToSO3(Eigen::Quaterniond egQ) {
	Eigen::Matrix3d egR;
	cv::Matx33d cvR;
	egR = egQ.toRotationMatrix();
	cv::eigen2cv(egR, cvR);

	return cvR;
}

//* -convert CV's custom quaternion to CV SO(3) 
//* @param: q   quaternion
cv::Matx33d SO3Mapping::CVQuatToSO3(cv::Vec4d &q) {
	double q0 = q(0);                   //* scalar part of quaternion
	cv::Vec3d q_vec(q(1), q(2), q(3));  //* vector part of quaternion

	cv::Matx33d result;
	result = cv::Matx33d::eye() + 2*hat(q_vec)*hat(q_vec) +2*q0*hat(q_vec);
	return result;
}



//* ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
//* Not-important funcitons
//* ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
//* -Priting functions 
//* @param: egQ   Eigen quaternion 
void SO3Mapping::printEigenQuat(Eigen::Quaterniond egQ){
	std::cout << egQ.w() << std::endl;
	std::cout << egQ.vec() << std::endl;
}

//* -round very small double to zero 
//* @param: cvR   3x3 matrix 
void SO3Mapping::roundTinyDoubleToZero(cv::Matx33d & cvR) {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if (std::abs(cvR(i, j)) < 0.0000001) {
				cvR(i, j) = 0;
			}
		}
	}
}

//* ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
//* hat and vee map
//* ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
//* -hat map 
//* @param: v   3x1 vector
cv::Matx33d SO3Mapping::hat(const cv::Vec3d &v) const {
	double v1 = v(0);
	double v2 = v(1);
	double v3 = v(2);
	cv::Matx33d result(0, -v3, v2, v3, 0, -v1, -v2, v1, 0);
	
	return result;
}

//* -vee map 
//* @param: m   3x3 skew-symmetric matrix
cv::Vec3d SO3Mapping::vee(const cv::Matx33d &m) const {
	double v1 = m(2, 1);  //* row 3, column 2
	double v2 = m(0, 2);  //* row 1, column 3 
	double v3 = m(1, 0);  //* row 2, column 1 

	cv::Vec3d result(v1, v2, v3);
	return result;
}