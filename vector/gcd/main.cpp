/* *********************************************************
Author:      Roy Wu
Description: Given a integer array, find the gratest common divisor (gcd) among the elements
********************************************************* */
#include <iostream>
#include <vector>
#include <algorithm> //* copy
#include <iterator>  //* ostream_iterator
#include <string>    //* to avoid error C2679
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream_iterator; //* writes an output stream

int findGCD(int number, int *arr);

int main(){
	//* array pointer
	int arr[] = { 30, 150, 300, 120, 90 };
	cout << "2nd element of the array is ..."  << *(arr+1) << endl;
	int num = sizeof(arr) / sizeof(arr[0]);
	cout << "Total number of elements in the array is ... " << num << endl;

	int *arrPtr = arr;
	int gcd = findGCD(num, arrPtr);
	cout << "gcd is...." << gcd << endl;
		
	return 0;
}

int findGCD(int num, int *arr) 
{
	cout << "function starts herer...\n";
	//* find the minimum element in the array
	int min = arr[0];
	for (int i = 1; i < num; i++) 
	{
		if (min - arr[i] > 0) 
			min = arr[i];
	}
	cout << "Minimal element is..." << min << endl;

	//* find all the divisors of min and put them into a vector
	vector<int> divi;
	for (int i = 1; i <= min; i++) 
	{
		if (min%i == 0) 
		{
			divi.push_back(i);
			cout << "i is..." << i << endl;
		}
	}

	//* use a reverse iterator to access elements from the end
	vector<int>::reverse_iterator ritr;
	bool isItADivisor;
	int gcd;
	for (ritr=divi.rbegin(); ritr!=divi.rend(); ++ritr)
	{
		isItADivisor = true;
		for (int i = 0; i < num; i++)
		{
			if (arr[i] % (*ritr) != 0)
			{
				cout <<"ritr is ... " << *ritr << endl;
				isItADivisor = false;
			}			
		}

		if (isItADivisor == true)
		{
			gcd = *ritr;
			break;
		}

	}
	return gcd;
}

