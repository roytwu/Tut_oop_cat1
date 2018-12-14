/* file name: main.cpp
 * programmer: Roy T Wu
 * Project: vector of struct*/

#include <iostream>
#include <vector>
#include <string>
using std::cout; 
using std::endl;
using std::vector;
using std::string; 

class AppHolder {
private:
	struct Info {
		int m_refNumber;
		string m_name;
		string m_link;
	};
	
	vector<Info> v_dataBase;

public:
	void AddNewApp(int, string, string);
};

void AppHolder::AddNewApp(int foo, string bar, string koo) {
	Info o_newApp;
	o_newApp.m_refNumber = foo;
	o_newApp.m_name = bar;
	o_newApp.m_link = koo;

	v_dataBase.push_back(o_newApp);
}


int main()
{
    cout << "Hello World" << endl;
	AppHolder o_toto; 
	o_toto.AddNewApp(1010, "app_name", "app_link");

    return 0;
}

