//* File name:   main.cpp (explicit)
//* Programmer:  Roy T Wu
//* Description: Demo of keyword 'explicit'

#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Core>              //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>             //* Eigen library: Matrix
#include <Eigen/Geometry>          //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> 
using std::cout; 
using std::endl;
using std::string; 


class Complex {
public:
	//* constructor
	//* use keyword explicit to avoid implicit conversion
	explicit Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

	//* a method to compare 2 complex numbers
	//* overloading '==' operator
	bool operator == (Complex rhs) {
		return (real == rhs.real && imag == rhs.imag) ? true : false;
	}

private:
	double real;
	double imag;
};



int main()
{
	Complex o_cmplx(3.0, 1.0);

	//* With explicit keyword defined in class, 
	//* we have to explicitly typecast the double values to Complex
	if (o_cmplx == (Complex)3.0)
		cout << "same\n";
	else
		cout << "not same\n";

    return 0;
}

