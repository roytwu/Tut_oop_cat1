/* ********************************************************* 
Author:      Roy Wu
Description: Templates allows one to create a single function/class to work with different data types. 
             Templates are often used in larger codebase for the purpose of 
			 code reusability and flexibility of the programs.
********************************************************* */
#include <iostream>
#include <memory>
#include "CusArray.hpp"
#include "MySeq.hpp"
using std::cout;
using std::endl;

int main(){
	//* =====class template, Cur_Array=====
	cout << "\n----- class template, Cur_Array-----\n";
	int          arrInt[5]   = { -1, -2, 3, 4, 5 };
	unsigned int arrUnInt[5] = { 1, 2, 3, 4, 5 };
	double       arrDou[5]   = { 0.1, 2.2, 33.3, 0.444, 5 };

	CusArray<unsigned int>  o_foo(arrUnInt, 5);
	o_foo.print();
	std::shared_ptr<CusArray<int>> o_bar = std::make_shared<CusArray<int>>(arrInt, 5);
	o_bar->print();
	
	//* =====class template, MySeq=====
	cout << "\n----- class template, MySeq-----\n";
	MySeq<> o_double;             //* not need to specify parameters here
	o_double.setMember(0, 100.2);
	o_double.setMember(2, 123.5);
	cout << o_double.getMember(2) << endl;

	//* shared pointer example
	std::shared_ptr<MySeq<int, 5>> o_int = std::make_shared< MySeq<int, 5> >();
	o_int->setMember(0, 100);
	o_int->setMember(2, 123);
	cout << o_int->getMember(2) << endl;

	return 0;
}

