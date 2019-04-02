#include <iostream>
#include "rotationVector.h"

//* ----- convert rotation vector to unit quaternion -----
cv::Vec4d RotVec::rotVecToQuat(const cv::Vec3d &rv) {
	double rv_x = rv(0);  
	double rv_y = rv(1);  
	double rv_z = rv(2);  
	double rv_norm = cv::norm(rv);
	
	double q0 = cos(rv_norm / 2);
	double q1 = sin(rv_norm / 2) * rv_x / rv_norm;
	double q2 = sin(rv_norm / 2) * rv_y / rv_norm;
	double q3 = sin(rv_norm / 2) * rv_z / rv_norm;
	
	cv::Vec4d quat(q0, q1, q2, q3);
	return quat;
}


//* ----- convert Rodrigues formula to rotation vector -----
cv::Vec3d RotVec::rodriguesToRotVec(const cv::Vec4d &rod) {
	double theta = rod(0);
	cv::Vec3d rotVec(rod(1), rod(2), rod(3));
	
	rotVec = theta*rotVec;
	return rotVec;
}