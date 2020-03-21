/* ********************************************************* 
Author:      Roy Wu
Description: Templates allows one to create a single function/class to work with different data types. 
             Templates are often used in larger codebase for the purpose of 
			 code reusability and flexibility of the programs.
********************************************************* */
#include <iostream>
#include "CusArray.hpp"
#include "MySeq.hpp"
using std::cout;
using std::endl;

int main(){
	//* class template, Cur_Array
	cout << "\n----- class template, Cur_Array-----\n";
	int    arr_int[5] = { 1, 2, 3, 4, 5 };
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

	return 0;
}

