//* File name:   main.cpp
//* Programmer:  Roy T Wu
//* Description: demo of std::move()

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <Eigen/Core>              //* this needs to added before <opencv2/core/eigen.hpp>
#include <Eigen/Dense>             //* Eigen library: Matrix
#include <Eigen/Geometry>          //* Eigen library: quaternion
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp> 
using std::cout; 
using std::endl;
using std::string; 
using std::vector;



int main()
{
	string str = "Hello World!";
	vector <string> vs;

	vs.push_back(str);
	cout << vs[0] << endl;

	//* no string will be copied, instead, the contents of str will be moved into the vector
	//* this is less expensive, but str will be empty after move
	vs.push_back(std::move(str));

	cout << "After move, str is ... " << str << endl;

	cout << "After move, vector is ... " << vs[0] << " " << vs[1] << endl;

    return 0;
}

