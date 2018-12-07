/*
* function template.cpp 
* platform: Visual Studio 2015
*/

#include <iostream>
using std::cout;
using std::endl;


// function template accept single parameter
template <class FT>
FT getMax(FT a, FT b) {
	FT result;
	result = (a>b) ? a : b;
	return(result);
}

// function template accept more than one parameter
template <class FT1, class FT2>
FT1 getMin(FT1 a, FT2 b) {
	FT1 result;
	result = (a < b) ? a : b;
	return(result);
}


// class template
template <class CT>
class Cus_Array {
private:
	CT  *ptr;
	int size;
public:
	Cus_Array(CT arr[], int s);
	void print();
};

template <class CT>
Cus_Array<CT>::Cus_Array(CT arr[], int s) {
	ptr = new CT[s];
	size = s;
	for (int i=0; i<size; i++) {
		ptr[i] = arr[i];
	}
}

template <class CT>
void Cus_Array<CT>::print() {
	for (int i=0; i<size; i++) {
		cout << " " << *(ptr + i);
	}
	cout << endl;
}

int main(){
	//function template output
	cout << getMax<int>(5, 6)           << endl;
	cout << getMax<double>(7.9, 3.1)    << endl;
	cout << getMin<double, int>(1.3, 9) << endl;

	//class template output
	cout << endl;
	int arr_int[5] = { 1, 2, 3, 4, 5 };
	double arr_dou[5] = { 0.1, 2.2, 33.3, 0.444, 5 };
	Cus_Array<int>  foo(arr_int, 5);
	foo.print();

	Cus_Array<double> bar(arr_dou, 5);
	bar.print();


	return 0;

}

