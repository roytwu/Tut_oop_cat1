/* *********************************************************
File name:   main.cpp (operator overload)
Developer:   Roy Wu
Last upate:  01/25/2019
Description: 
    1. illustrating basic concepts of operator overloading
    2. demonstrating assignment operator (=) overloading and compare it with copy constructor
********************************************************* */

#include <iostream>
#include <string>

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


class Test {
public:
	//* default constructor
	Test() : id(0), name("") {}

	//* overloaded constructor
	Test(int id, string name): id(id), name(name){}

	void print() {
		cout << id << ": " << name << endl << endl;
	}

	//* overloading assignment operator
	const Test &operator=(const Test &other) {
		cout << "Assignment running!" << endl;
		id = other.id + 1;
		name = other.name;
		return *this;
	}

	//* copy constructor
	Test(const Test &other) {
		cout << "Copy constructor running!" << endl;
		id = other.id + 10;
		name = other.name;
	}

private:
	int id;
	string name;
};



int main(){
	Bar o_bar;

	//* using pointer
	Foo *ptr = &o_bar;
	(*ptr)(); //* clumsy! - prints bar!

	//* using reference 
	Foo &ref = o_bar;
	ref(); //* better - prints bar!

	//* also correct
	o_bar(); //* prints bar!

    
	//* overloading assignment operator
	cout << endl << endl;
	Test o_test1(01, "Tiguan");
	Test o_test2(02, "Atlas");
	Test o_test3(03, "Passat");

	o_test1.print();
	
	o_test2 = o_test1; //* shallow copy, copy all the valus from o_test1 to o_test2
	o_test2.print();
	
	o_test3.operator= (o_test2); //* equlas to o_test3 = o_test2
	o_test3.print();

	//* If you take an object and not giving initial values, 
	//* and immediately assign this object to another object, it do not ues the assignment operator (=)
	//* it is using copy constructor
	Test o_test4 = o_test1; //* copy initilization, implicit invoking copy consturctor
	o_test4.print();

	
	return 0;
}

