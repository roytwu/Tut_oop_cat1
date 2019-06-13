/* *********************************************************
File name:   main.cpp 
Programmer:  Roy Wu
Description: using virtaul functions to achieve runtime polymorphism
********************************************************* */
//#include <array>               //* std::array
#include <iostream>
#include <string>
#include <vtkMath.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>

using std::cout; 
using std::endl;

class Base 
{
public:
	virtual void print() { cout << "print base class\n"; }
	        void show()  { cout << "show base class\n"; }
};

class Derived : public Base
{
public:
	//* print() is already a virtual function in derived class
	void print() {
		cout << "print drived class\n";
	}

	void show() {
		cout << "show derived class\n";
	}
};


int main()
{
	Base    *ptr_base;
	Derived o_d1;

	//* prt_base conatins the address of object o_d1
	ptr_base = &o_d1;

	//* runtime polymorphism: virtual function is binded at runtime
	ptr_base->print();

	//* non-virutal function, binded at compile time
	ptr_base->show();

	return 0;
}