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


	//* no-type template
	cout << "\n----- no-type template-----\n";
	int toto = Factorial<5>::value;
	int tata = Factorial<0>::value;
	cout << toto << ", " << tata << endl; 

	return 0;
}

