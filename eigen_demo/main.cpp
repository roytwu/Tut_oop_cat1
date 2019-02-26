#include <iostream>
#include <string>
#include <Eigen/Dense>  
#include <Eigen/Geometry>

using std::cout; 
using std::endl;
using std::string;

int main()
{
	//* ===== Matrix Class =====
	//* declare a 3x3 matrix of double
	Eigen::Matrix3d eye3 = Eigen::Matrix3d::Identity();
	cout << eye3 << endl  << endl;

	//* declare a 3x1 matrix of double
	//* vectors are just special cases of matrices. by default the Vector in Eigen are column-vectors
	Eigen::Vector3d v1(5.8, 2.1, 3.0);
	cout << v1 << endl << endl;

	//* decalre a 1x3 row-vector of double
	Eigen::RowVector3d rv1(3, 5, 9);
	cout << rv1 << endl << endl;

	//* matrix multiplication
	//* dynamic matrix, i.e., size of the matrix is unknown at compile time, 
	//* and it is handled as a run-time variable
	Eigen::MatrixXd m1 = eye3*v1*rv1; 
	cout << m1 << endl << endl;

	//* matrix transpose
	Eigen::Matrix3d m1T = m1.transpose();
	cout << m1T << endl;

	//* ===== Quaternion Class =====
	//* quaternion for double
	Eigen::Quaterniond q1(2, 0, 1, -3);
	cout << "scalar part of the quaternion is ... " << q1.w() << endl;
	cout << "vector part of the quaternion is ... " << endl	<< q1.vec() << endl;

	//* length of the quaternion 
	cout << "length of q1 is ... " << q1.norm() << endl << endl;

	//* quaternion identity
	Eigen::Quaterniond eyeQ = Eigen::Quaterniond::Identity();
	cout << eyeQ.w() << endl;
	cout << eyeQ.vec() << endl;

	//* quaternion multiplication
	Eigen::Quaterniond q2 = q1*eyeQ;

	//* convert a quatternion to a rotation matrix
	Eigen::Matrix3d r1 = eyeQ.toRotationMatrix();
	cout << r1 << endl;

}

