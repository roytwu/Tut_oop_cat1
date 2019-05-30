//* File name:   main.cpp (explicit)
//* Programmer:  Roy T Wu
//* Description: 

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
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

	//* a method to compare 2 complex numbers
	bool operator == (Complex rhs) {
		return (real == rhs.real && imag == rhs.imag) ? true : false;
	}

private:
	double real;
	double imag;
};



int main()
{


    return 0;
}

