/* *********************************************************
File name:   main.cpp (function template)
Programmer:  Roy Wu
Description: static class members/member funcitons
********************************************************* */

//#include <iostream>
//#include <string>
#include <vector>
#include <Eigen/Core>              //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>             //* Eigen library: Matrix
#include <Eigen/Geometry>          //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include "account.h"


//using std::cout; 
//using std::endl;
//using std::string; 

int main()
{
	//* access a static member using the scope operator
	//* note that there is no Account object 
	double r = Account::findRate();
	cout << r << endl;


	//* access static member by using an object, reference or pointer
	Account o_ac1;
	Account * o_ac2 = &o_ac1;

	r = o_ac1.findRate();  //* through an Account object
	r = o_ac2->findRate(); //* through a pointer to an Account object



	//* through an Account object reference
	double result = ref_a().findRate();
	cout << result << endl;

    return 0;
}

