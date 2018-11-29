/*
* function template.cpp 
* platform: Visual Studio 2015
*/

/* 
* Function templates are special functions that can operate with generic types.
* This allows us to create a function template whose functionality can be adapted to 
* more than one type or class without repeating the entire code for each type.
*/

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;

// class template accept single parameter
template <class T>
T getMax(T a, T b) {
	T result;
	result = (a>b) ? a : b;
	return(result);
}

// class template accept more than one parameter
template <class T, class U>
T getMin(T a, U b) {
	T result;
	result = (a < b) ? a : b;
	return(result);
}

int main(){
	cout << getMax<int>(5, 6) << endl;
	cout << getMax<double>(7.9, 3.1) << endl;

	cout << getMin<double, int>(1.3, 9) << endl;

	return 0;

}

