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



int main()
{
	string foo = "1234567890";
	string bar = "123456";

	equalizeLength(foo, bar);
	cout << foo << endl;
	cout << bar << endl;

    return 0;
}

