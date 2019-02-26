#include <iostream>
#include <string>
#include <Eigen/Dense> 

using std::cout; 
using std::endl;
using std::string;

int main()
{
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


}

