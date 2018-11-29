
#include "stdafx.h"
#include <iostream>

using std::cout; 
using std::endl;

class Foo {
public:
	virtual void operator()() {
		cout << "foo!" << endl;
	}
};

class Bar : public Foo {
public:
	virtual void operator()() {
		cout << "bar!" << endl;
	}
};



int main()
{
	Bar o_bar;

	//using pointer
	Foo *ptr = &o_bar;
	(*ptr)(); //clumsy! - prints bar!

	//using reference 
	Foo &ref = o_bar;
	ref(); //better - prints bar!

	//also correct
	o_bar(); //prints bar!

    return 0;
}

