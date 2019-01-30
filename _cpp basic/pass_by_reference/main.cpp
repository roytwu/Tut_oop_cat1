/* file name: main.cpp
 * programmer: Roy T Wu
 * Project: pass by reference */

#include <iostream>
#include <vector>
#include <string>
using std::cout; 
using std::endl;
using std::vector;
using std::string; 

//* declare the funciton parameters as reference rather then as normal variables
void equalizeLength(string& str_1, string& str_2) {
	if (str_1.size() > str_2.size()) {
		while (str_1.size() > str_2.size()) {
			str_2.append("0");
			for (int i = str_2.size() - 1; i > 0; i--) {
				std::swap(str_2[i], str_2[i - 1]);
			}
		}
	}
}


void swapNumber(int& i, int& j) {
	//* when the funciton is called, i and j will become a reference to the argument
	//* since a reference to a variable is treated exactly the same as the variable itself,
	//* any changes made to the reference are passed through to the argument
	int temp = i;
	i = j;
	j = temp;
}


int main()
{
	string foo = "1234567890";
	string bar = "123456";

	equalizeLength(foo, bar);
	cout << foo << endl;
	cout << bar << endl << endl;

	int a=99, b = 77;
	swapNumber(a, b);
	cout << a << " " << b << endl;

    return 0;
}

