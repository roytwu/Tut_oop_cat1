//file name: map_basic.cpp
//programmer: Roy T Wu
//Basic commands about <map> in C++

#include <iostream>
#include <string>
#include <map>
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::string;
using std::map;


int main(){
	map<string, int> ages;

	//adding members to map, method#1
	ages["Mike"] = 40;
	ages["Raj"] = 25;
	ages["Vicky"] = 30;
	ages["Mike"] = 67;

	//adding members to map, method#2
	pair<string, int> addToMap("Peter", 99);
	ages.insert(addToMap);

	//adding members to map, method#3
	ages.insert(pair<string, int>("Annie", 1));

	//adding members to map, method#4
	ages.insert(make_pair("Andy", 28));


	//access the value
	cout << ages["Raj"] << endl;


	//Try to find a key in the map
	if(ages.find("Vicky") != ages.end()){
		cout << "Found Vicky!" << endl;		
	}else {
		cout << "Key is not found.." << endl;
	}


	//print out the map, mathod1
	map<string, int>::iterator itr;
	for(itr=ages.begin(); itr!=ages.end(); itr++){
		cout << (itr->first) << ": " << (itr->second) << endl;
	}
	cout << endl;

	//print out the map, method 2
	for(itr=ages.begin(); itr!=ages.end(); itr++){
		pair<string, int> age_pair = *itr;
		cout << (age_pair.first) << ": " << (age_pair.second) << endl;
	}


	return 0;
}