/* file name: main.cpp
 * programmer: Roy T Wu
 * Project: enumeration */

#include <iostream>
#include <vector>
#include <string>
using std::cout; 
using std::endl;
using std::vector;
using std::string; 

namespace RoySpace {
	enum class Color_A {
		bronze, silver, gold
	};

	enum class Color_B {
		bronze, silver, gold, red, green, blue
	};
}


using namespace RoySpace;

int main()
{
    cout << "Hello World" << endl;
	Color_A clrA = Color_A::gold; 
	Color_B clrB = Color_B::gold;

	cout << clrA << endl;
    return 0;
}

