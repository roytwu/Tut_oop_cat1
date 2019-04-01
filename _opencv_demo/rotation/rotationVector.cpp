#include <iostream>
#include "rotationVector.h"

//* ----- convert rotation vector to OpenCV's quaternion -----
cv::Vec4d RotVec::rotVecToQuat(cv::Vec3d &rv) {
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
//cv::Vec3d rodriguesToRotVec(cv::Vec4d &rod) {
//
//}