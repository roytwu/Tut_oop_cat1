#include <iostream>
//#include <string>


using std::cout; 
using std::endl;
using std::string;

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
	const string cmake_system_name = SYSTEM_NAME;
	cout << "Hello from " << cmake_system_name << endl << endl;

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

