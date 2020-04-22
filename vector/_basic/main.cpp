/* *********************************************************
Author:      Roy Wu
Description: basic concepts and syntax about vectors
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
using std::copy; //* copy elements from its input range into elements in the destination
using std::ostream_iterator; //* writes an output stream

vector<string> func_GetString();


int main(){
	size_t size = 10;
	//* Element count
	vector<int> vec0;       //* declare an empty vector
	vector<int> vec1(size); //* declare a vector of size 10 with all values as 0

	//* list initializer: use the value inside the curly braces as a list of element 
	vector<int> vec2(size, 99); //* declare a vector of size 10 with all values as 99
	for(unsigned int i=0; i<size; i++){
		vec1[i] = i;
		vec2[i] = vec2[i]+i;
	}
	cout << "vec1[1] is " << vec1[1] << endl;
	cout << "vec2[1] is " << vec2[1] << "\n\n";

	vector<int> vecA(10,1); //* vecA has 10 elements with value 1 (Element Count)
	vector<int> vecB{10,1}; //* vecB has 2 elements with values 10 and 1 (List Initializer)
	cout << "vecA is ... ";
	copy(vecA.begin(), vecA.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "vecB is ... ";
	copy(vecB.begin(), vecB.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	vecA = vecB;  //* copy elements of vecB into vecA, 2 vectors must be the same type
	cout << "After copy, vecA is ... ";
	copy(vecA.begin(), vecA.end(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;


	//* initialize a vector like array
	vector<double> vec3{1.01, 2.002, 3.0003}; 

	//* initialize a vector from another vector
	vector<double> vec4( vec3.begin(), vec3.end()); 
	
	//* range-based for loop
	cout << "vec3 is ... ";
	for (double x : vec3){ cout << x << " "; }
	cout << endl;

	//* use keyword "auto" in the range-based for loop
	cout << "vec4 is ... ";
	for (auto x : vec4){ cout << x << " "; }
	cout << endl << endl;


	//* ---declare a function that returns vector---
	vector<string> vec_str = func_GetString();
	
	//* print the first element in the vector
	cout << vec_str[0] << endl;   

	//* delcare a iterator itr, it can read and write vector<string> elements
	vector<string>::iterator itr; 

	//* accessing elements using iterators
	//* One can dereference an iterator to obtain the element denoted by the iterator
	for(itr=vec_str.begin(); itr!=vec_str.end(); itr++){
		cout << *itr << " ";
	}
	cout << endl;
	

	//* Use range-based for loop to print (compared to using iterator)
	cout << endl << "Range-based for loop goes.." << endl;
	for (auto str : vec_str) {
		cout << str << " ";
	}
	cout << endl << endl;

	return 0;
}


//* push_back: takes a value and "pushes" that value onto the "back" of the vector
vector<string> func_GetString(){
	vector<string> v_str;
	v_str.push_back("One");
	v_str.push_back("Two");
	v_str.push_back("Three");
	v_str.insert(v_str.begin(), "zero"); //* insert "zero" at front
	return v_str;
}



/*-----Note-----*/
//* Define a vector of specific size can result in poor performance
//* Starting with an empty vector and adding elements at run time is a better approach

