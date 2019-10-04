#include "quaternion.h"

//* ----- ----- quaternion multiplication ----- -----
//* @param p    quaternion
//* @param q    quaternion
cv::Vec4d S3::quatMultiplication(const cv::Vec4d &p, const cv::Vec4d &q) {
	double p0 = p(0);  //*scalar part
	double p1 = p(1);  //*vector part x
	double p2 = p(2);  //*vector part y
	double p3 = p(3);  //*vector part z

	double q0 = q(0);
	double q1 = q(1);
	double q2 = q(2);
	double q3 = q(3);

	double r0 = p0 * q0 - (p1 * q1 + p2 * q2 + p3 * q3);
	double r1 = p0 * q1 + q0*p1 + (p2 * q3 - p3 * q2);
	double r2 = p0 * q2 + q0*p2 + (p3 * q1 - p1 * q3);
	double r3 = p0 * q3 + q0*p3 + (p1 * q2 - p2 * q1);

	cv::Vec4d r(r0, r1, r2, r3);
	r = r / norm(r);
	return r;
}

cv::Matx44d S3::rightToLeft(const cv::Vec4d & p) {
	double p0 = p(0);  //*scalar part
	double p1 = p(1);  //*vector part x
	double p2 = p(2);  //*vector part y
	double p3 = p(3);  //*vector part z

	cv::Matx14d row1(p0, -p1, -p2, -p3); //* 1x4
	cv::Matx34d row234;                  //* 3x4
	cv::Matx44d result;                  //* 4x4

	cv::Vec3d vecPart_vec(p1, p2, p3);
	cv::Matx31d vecPart_matx(p1, p2, p3); 

	cv::Matx33d dummy = p0*cv::Matx33d::eye() - S3::hat(vecPart_vec);
	cv::hconcat(vecPart_matx, dummy, row234);
	cv::vconcat(row1, row234, result);
	return result;
}

cv::Matx44d S3::quatMultMatx(const cv::Vec4d & p) {
	double p0 = p(0);  //*scalar part
	double p1 = p(1);  //*vector part x
	double p2 = p(2);  //*vector part y
	double p3 = p(3);  //*vector part z

	cv::Matx14d row1(p0, -p1, -p2, -p3); //* 1x4
	cv::Matx34d row234;                  //* 3x4
	cv::Matx44d result;                  //* 4x4

	cv::Vec3d vecPart_vec(p1, p2, p3);

	cv::Matx33d dummy = p0*cv::Matx33d::eye() + S3::hat(vecPart_vec);
	cv::hconcat(vecPart_vec, dummy, row234);
	cv::vconcat(row1, row234, result);
	return result;
}


//* ----- ----- quaternion inverse ----- -----
//* @param q    quaternion
cv::Vec4d S3::quatInverse(const cv::Vec4d &q) {
	cv::Vec4d q_conj = q.conj(); 

	//* normalized conjugation leads to quaternion verse
	cv::Vec4d q_inv = q_conj / cv::norm(q);
	return q_inv;
}


//* ----- ----- convert CV's quaternion to CV SO(3) ----- -----
//* @param q    quaternion
cv::Matx33d S3::cvQuatToSO3(const cv::Vec4d &q) {
    
	cv::Vec4d nq = q / cv::norm(q); //* noramlized q

	double q0 = nq(0);                    //* scalar part of q
	cv::Vec3d q_vec(nq(1), nq(2), nq(3)); //* vector part of q

	cv::Matx33d result;
	result = cv::Matx33d::eye() + 2 * hat(q_vec)*hat(q_vec) + 2 * q0*hat(q_vec);
	return result;
}


//* -mapping SO(3) to OpenCV's quaternion
//* @param: rotm   rotation matrix   
cv::Vec4d S3::SO3ToCVQuat(cv::Matx33d const& rotm) {
	double tr = cv::trace(rotm);
	double q0 = sqrt(tr + 1.0) / 2;    //* ambiguity
									   //double q0 = -sqrt(tr + 1.0) / 2; //* ambiguity

	cv::Vec3d dummy = vee(rotm - rotm.t());
	dummy = dummy / (4 * q0);

	cv::Vec4d q(q0, dummy(0), dummy(1), dummy(2));
	return q;
}


//* convert angle-axis representation to quaternionn
//* @param aa     attitude in angle-axis representaiton (Rodrigues formula)
cv::Vec4d S3::rodriguesToQuat(const cv::Vec4d & aa) {
	double    angle = aa[0];
	cv::Vec3d axis(aa[1], aa[2], aa[3]);
	
	axis = axis / cv::norm(axis);  

	double    q0 = cos(angle / 2);
    cv::Vec3d qv = sin(angle / 2)*axis;

	cv::Vec4d q(q0, qv[0], qv[1], qv[2]);
	return q;
}


//* convert angle-axis representation rotation matrix
//* @param aa     attitude in angle-axis representaiton (Rodrigues formula)
cv::Matx33d S3::rodriguesToSO3(const cv::Vec4d & aa) {
    double    angle = aa[0];
    cv::Vec3d axis(aa[1], aa[2], aa[3]);
    
    axis = axis / cv::norm(axis);

    cv::Matx33d eye = cv::Matx33d::eye();
    cv::Matx33d R = eye + sin(angle)* hat(axis) + (1 - cos(angle))*hat(axis)*hat(axis);
    return R;
}


//* convert rotation matrix to angle-axis representation
//* @param aa     attitude in angle-axis representaiton (Rodrigues formula)
cv::Vec4d S3::SO3ToRodrigues(const cv::Matx33d &R) {
    double tr = cv::trace(R);
    double theta = acos(0.5*(tr - 1));
    cv::Vec4d output;

    if (theta == 0) 
    {
        //* if thetat =0. null rotation
        output = cv::Vec4d(0, 1, 0, 0);
    }
    else 
    {
        double dummy = 1 / (2 * sin(theta));
        cv::Matx33d axisHat = dummy*(R - R.t());
        cv::Vec3d axis = vee(axisHat);
        output = cv::Vec4d(theta, axis(0), axis(1), axis(2));
    }
 
    return output;
}


//* ----- ----- hat map ----- -----
//* @param v    a 3x1 vector
cv::Matx33d S3::hat(const cv::Vec3d &v) {
	double v1 = v(0);
	double v2 = v(1);
	double v3 = v(2);
	cv::Matx33d result(0, -v3, v2, v3, 0, -v1, -v2, v1, 0);

	return result;
}


//* -vee map 
//* @param: m   3x3 skew-symmetric matrix
cv::Vec3d S3::vee(const cv::Matx33d &m) 
{
	double v1 = m(2, 1);  //* row 3, column 2
	double v2 = m(0, 2);  //* row 1, column 3 
	double v3 = m(1, 0);  //* row 2, column 1 

	cv::Vec3d result(v1, v2, v3);
	return result;
}
