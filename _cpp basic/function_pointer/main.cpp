/* file name: main.cpp
 * programmer: Roy T Wu
 * Project: function pointer */

#include <iostream>
#include <vector>
#include <string>
using std::cout; 
using std::endl;
using std::vector;
using std::string; 


//* a function with void return type and no parameters
void test_al() {
	cout << "Hello, I am a test function alpha!" << endl;
}

//* a function with void return type and 2 parameters
void test_be(int v_int, string v_str) {
	cout << "Hello, I am a test function beta" << endl;
	cout << v_int << ", " << v_str << endl;
}

int main()
{
	//* calling up function in a regular way
	test_al();

	//* a variable called p_testA, which is a pointer to function with a void return type and no parameters
	void(*p_testA)();
	void(*p_testB)();

	//* syntax1
	p_testA = &test_al;
	(*p_testA)();

	//* syntax2
	p_testB = test_al;
	p_testB();

	//* syntax3
	void(*p_testC)() = test_al;
	p_testC();

	//* a pointer to a function that take parameter type int and string and return void
	void(*p_testD)(int, string) = test_be;
	p_testD(8, "cool");


    return 0;
}

