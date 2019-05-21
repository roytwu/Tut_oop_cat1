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


//* ---function template accept single parameter---
template <typename FT>
FT getMax(FT a, FT b) {
	FT result;
	result = (a>b) ? a : b;
	return(result);
}

//* ---function template accept more than one parameter---
template <class FT1, class FT2>
FT1 getMin(FT1 a, FT2 b) {
	FT1 result;
	result = (a < b) ? a : b;
	return(result);
}


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



//* ---no-type template: template metaporgramming---
template <int N>
struct Factorial {
	enum { value = N*Factorial<N-1>::value };
};

template <>
struct Factorial<0> {
	enum { value=1 };
};



//* ---main body---
int main(){
	cout << "\n----- function template-----\n";
	//* function template output
	cout << getMax<int>(5, 6)           << endl;
	cout << getMax<double>(7.9, 3.1)    << endl;
	cout << getMin<double, int>(1.3, 9) << endl;

	//* class template, Cur_Array
	cout << "\n----- class template, Cur_Array-----\n";
	int arr_int[5] = { 1, 2, 3, 4, 5 };
	double arr_dou[5] = { 0.1, 2.2, 33.3, 0.444, 5 };
	Cus_Array<int>  o_foo(arr_int, 5);
	o_foo.print();

	Cus_Array<double> o_bar(arr_dou, 5);
	o_bar.print();


	//*class template, MySeq
	cout << "\n----- class template, MySeq-----\n";
	MySeq<> o_double;             //* not need to specify parameters here
	o_double.setMember(0, 100.2);
	o_double.setMember(2, 123.5);
	cout << o_double.getMember(0) << endl;


	//* no-type template
	cout << "\n----- no-type template-----\n";
	int toto = Factorial<5>::value;
	int tata = Factorial<0>::value;
	cout << toto << ", " << tata << endl; 

	return 0;
}

