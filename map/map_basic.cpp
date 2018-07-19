#include <iostream>
#include <string>
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::map;

int main(){
	map<string, int> ages;

	ages["Mike"] = 40;
	ages["Raj"] = 25;
	ages["Vicky"] = 30;

	cout << ages["Raj"] << endl;

	return 0;
}