/* *********************************************************
Authro:      Roy Wu
Description: examples of funcitons in std::algorithm
********************************************************* */
#include <iostream>
#include <string>
#include <vector>
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
	vector<int> v = { 1, 2, 3, 3, 3, 66, 1, 2, 3, 7, 7, 8 };
	vector<int>::iterator ip;

	//* sorting the array
	std::sort(v.begin(), v.end());
	cout << "After sortig the array...\n";
	for (auto i : v) { std::cout << i << " "; }
	cout << endl;

	
	/* --- std::find() ----*/ 
	cout << "\n----- std::find() -----\n";
	int target = 2; //* elements to be searched

	//* iterator used to store the position of searched element
	vector<int>::iterator it;

	//* function call of find()
	it = std::find(v.begin(), v.end(), target);

	if (it != v.end()) {
		cout << "Element ``" << target << "'' found at position: " 
			 << it -v.begin()+1 << endl;
	}
	else {
		cout << "Element not found...\n";
	}


	//* applying unique() to remove duplicate elements
	//* aftering calling unique(), a call to resize the container is typicall
	ip = std::unique(v.begin(), v.end());

	//* resizing the vector so as to remove the undefined terms
	auto new_size = std::distance(v.begin(), ip);
	v.resize(new_size);

	//* displaying the vector after applying unique()
	cout << "\nAfter unique() the array...\n";
	for (ip = v.begin(); ip != v.end(); ++ip) {
		cout << *ip << " ";
	}
	cout << endl;

    return 0;
}

