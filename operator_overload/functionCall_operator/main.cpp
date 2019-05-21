/* *********************************************************
File name:   main.cpp (overloading function-call operator)
Developer:   Roy Wu
Last upate:  05/20/2019
Description: 
********************************************************* */

#include <iostream>
#include <string>

#include "distance.hpp"

using std::cout; 
using std::endl;
using std::string;


int main(){
	
	Distance D1(2, 10);
	Distance D2;

	cout << "Distance is ... \n";
	D1.displayDistance();

	D2 = D1(2); // invoke operator()
	cout << "\nDistance multiplier is ... \n";
	D2.displayDistance();


	
	return 0;
}

