/* ********************************************************* 
File name:   function template.cpp 
Programmer:  Roy Wu
Description: Templates allows you to create a single function/class to 
             work with different data types. Templates are often used in larger codebase for the purpose of
             code reusability and flexibility of the programs.
********************************************************* */
#include <iostream>
using std::cout;
using std::endl;



//* ---class template---
template <class CT>
class Cus_Array {
public:
	//* constructor
	Cus_Array(CT arr[], int s);
	void print();

private:
	CT  *ptr;
	int size;
};

//* constructor
template <class CT>
Cus_Array<CT>::Cus_Array(CT arr[], int s) {
	ptr = new CT[s];
	size = s;
	for (int i=0; i<size; i++) {
		ptr[i] = arr[i];
	}
}

//* member function 
template <class CT>
void Cus_Array<CT>::print() {
	for (int i=0; i<size; i++) {
		cout << " " << *(ptr + i);
	}
	cout << endl;
}

//* ---class template example with default values and types---
template <class T =double, int N =10>
class MySeq {
public:
	void setMember(int x, T value);
	T getMember(int x);

private:
	T memBlock[N];
};


template <class T, int N>
void MySeq<T, N>::setMember(int x, T value) {
	memBlock[x] = value;
}


template <class T, int N>
T MySeq<T, N>::getMember(int x) {
	return memBlock[x];
}




//* ---main body---
int main(){

	//*class template, MySeq
	cout << "\n----- class template, MySeq-----\n";
	MySeq<> o_double;             //* not need to specify parameters here
	o_double.setMember(0, 100.2);
	o_double.setMember(2, 123.5);
	cout << o_double.getMember(0) << endl;


	return 0;
}

