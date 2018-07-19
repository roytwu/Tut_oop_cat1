//file name: map_custome.cpp
//programmer: Roy T Wu
//This is the OOP version of map_basic.cpp where a custom map is used

#include <iostream>
#include <string>
#include <map>
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::flush;
using std::string;
using std::map;


class Person{
private:
	string name;
	int age;
public:
	//unparameterized contructor
	Person(): name(""), age(0) {} //unparametrized constructor is required.

	//constructor overloading
	Person(string name, int age): name(name), age(age) {}

	//copy constructor
	Person(const Person &other){
		cout << "Copy constructor running!" << endl;
		name = other.name;
		age = other.age;
	}

	void printMap() const {
		cout << name << ": " << age << endl;
	}
};



int main(){
	map<int, Person> peopleMap;

	peopleMap[0] = Person("Mike", 40);
	peopleMap[8] = Person("Raj", 25);
	peopleMap[5] = Person("Vicky", 30);

	//this will call the copy constructor
	peopleMap.insert( make_pair(7, Person("Peter", 99)) );
	peopleMap.insert( make_pair(1, Person("Annie", 1)) );



	cout << "Key    Value" << endl;
	cout << "------------" << endl;
	map<int, Person>::iterator itr;
	for(itr = peopleMap.begin(); itr!=peopleMap.end(); itr++){
		cout << (itr->first) << "      " << flush;
		(itr->second).printMap();
	}

	return 0;
}