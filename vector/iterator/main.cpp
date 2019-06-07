/* *********************************************************
File name:   main.cpp (_iterator)
Programmer:  Roy Wu
Description: concepts and syntax about vector iterators
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

//* iterator use the increment operator (++) to "advance the iterator by one poisiton"
//* which is logically similar to integer increment

int main(){

	vector<int> vec1 = { 10, 20, 30, 30, 30, 66, 10, 20, 33, 70, 7, 8 };
	for (auto x : vec1) { cout << x << " "; }
	cout << endl;

	//* begin() returns an iterator pointing to 1st element
	//* One can dereference an iterator to obtain the element denoted by the iterator
	cout << "The 1st element is ... " << *(vec1.begin()) << endl;



	//* end() returns an iterator pointing to the imaginary element that follows last element 
	//* therefore, to print the last element, use end()-1
	cout << "The last element is ... " << *(vec1.end()-1) << "\n\n";


	//* --- use iterator to go through all the elements in the vector 
	//* delcare an iterator, which can be used to store the position of a element
	vector<int>::iterator itr;
	for (itr = vec1.begin(); itr != vec1.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	//* random-access iterators can be used with arithmetic operators
	for (itr = vec1.begin(); itr != vec1.end(); itr++) {
		cout << itr-vec1.begin()+1 << " ";
	}
	cout << endl;

	return 0;
}


