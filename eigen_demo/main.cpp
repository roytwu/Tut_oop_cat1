#include <iostream>
#include <string>
#include <Eigen/Dense>  
#include <Eigen/Geometry>

using std::cout; 
using std::endl;
using std::string;

int main()
{
	cout << "===== Matrix Class =====" << endl;
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
	cout << m1T << endl << endl;


	cout << "===== Quaternion Class =====" << endl;
	//* quaternion for double
	Eigen::Quaterniond q1(2, 0, 1, -3);
	cout << "scalar part of the quaternion is ... " << q1.w() << endl;
	cout << "vector part of the quaternion is ... " << endl	<< q1.vec() << endl;

	//* length of the quaternion 
	cout << "length of q1 is ... " << q1.norm() << endl << endl;

	//* return unit quaternion
	Eigen::Quaterniond uq1 = q1.normalized();
	cout << "scalar part of the unit quaternion is ... " << uq1.w() << endl;
	cout << "vector part of the unit quaternion is ... " << endl << uq1.vec() << endl;
	cout << "length of uq1 is ... " << uq1.norm() << endl << endl;

	//* quaternion identity
	Eigen::Quaterniond eyeQ = Eigen::Quaterniond::Identity();
	cout << eyeQ.w() << endl;
	cout << eyeQ.vec() << endl;

	//* quaternion multiplication
	Eigen::Quaterniond q2 = q1*eyeQ;

	//* convert a unit quatternion to a rotation matrix
	Eigen::Matrix3d r1 = uq1.toRotationMatrix();
	cout << r1 << endl << endl;

	cout << "===== Angle-axis Class =====" << endl;
	//* angle-axis, note the axis must be normalized
	Eigen::Vector3d axis1(0, 1, 0);
	Eigen::AngleAxisd aa1(0, axis1);
	
	Eigen::Quaterniond q3;
	q3 = aa1;   //* transfer from angle-axis representation to quaternion representation
	//* Note that Eigen::Quaterniond q3 = aa; wont' work. In the C++ language, 
	//*   this would require Transform to have a non-explicit conversion constructor from AngleAxis,
	//*   but Eigen does not allow implicit casting here 

	Eigen::AngleAxisd aa_foo;
	aa_foo = q1; //* transfer from quaternion representation to angle-axis representation
	//* notice that during this step, q1 will be normalized. 

	cout << aa_foo.angle() << endl;
	cout << aa_foo.axis()  << endl;
	Eigen::Matrix3d r_foo = aa_foo.toRotationMatrix();
	cout << r_foo << endl;
}

