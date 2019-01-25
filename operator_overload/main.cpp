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
		cout << id << ": " << name << endl;
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
	
	
	
	return 0;
}

