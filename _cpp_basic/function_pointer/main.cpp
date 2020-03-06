/* *********************************************************
File name:   main.cpp (_funcPtr)
Author:      Roy Wu
Description: basic concepts of funciton pointer
********************************************************* */
#include <iostream>
#include <vector>
#include <string>
using std::cout; 
using std::endl;
using std::vector;
using std::string; 


//* a function with void return type and no parameters
bool test_alpha() {
	cout << "Hello, I am test function alpha!" << endl;

	return true;
}

//* a function with void return type and 2 parameters
void test_beta(int v_int, string v_str) {
	cout << "Hello, I am test function beta" << endl;
	cout << v_int << ", " << v_str << endl;
}

int main()
{
	//* calling up function in a regular way
	test_alpha();

	//* a variable called p_testA, which is a pointer to function with void return type and no parameters
	bool(*p_testA)();
	bool(*p_testA2)();
	//* a variable called p_testB, which is a pointer to function with bool return type and no parameters
	void(*p_testB)();

	//* syntax1
	p_testA = &test_alpha;
	(*p_testA)();

	//* syntax2
	p_testA2 = test_alpha;
	p_testA2();

	//* syntax3
	bool(*p_testA3)() = test_alpha;
	p_testA3();

	//* a pointer to a function that take parameter type int and string and return void
	void(*p_testD)(int, string) = test_beta;
	p_testD(8, "cool");


    return 0;
}

