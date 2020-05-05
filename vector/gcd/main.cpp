/* *********************************************************
Author:      Roy Wu
Description: Given a integer array, find the gratest common divisor (gcd) among the elements
********************************************************* */
#include <iostream>
#include <vector>
#include <algorithm> //* copy
#include <iterator>  //* ostream_iterator
#include <string>    //* to avoid error C2679
#include "gcd.hpp"   //* gcd function


//int findGCD(int number, int *arr);

int main(){
	//* array pointer
	int arr[] = { 30, 150, 300, 120, 90 };
	//cout << "2nd element of the array is ..."  << *(arr+1) << endl;
	int num = sizeof(arr) / sizeof(arr[0]);
	//cout << "Total number of elements in the array is ... " << num << endl;

	int *arrPtr = arr;
	int gcd = findGCD(num, arrPtr);
	cout << "GCD is.... " << gcd << endl;
		
	return 0;
}



