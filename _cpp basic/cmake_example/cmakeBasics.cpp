#include <iostream>
#include <cstlib>

using std::cout;
using std::endl;

int main() {
	Message o_sayHello("Hello, CMake World!");
	cout << o_sayHello << endl;

	Message o_sayGoodBye("Goodby, CMake World!");
	cout << o_sayGoodBye << endl;

	return EXIT_SUCCESS;
}