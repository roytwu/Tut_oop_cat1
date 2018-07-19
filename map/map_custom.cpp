
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
	Person(): name(""), age(0) {}

	Person(string name, int age): name(name), age(age) {}

	void printMap() const {
		cout << name << ": " << age << endl;
	}
};



int main(){
	map<int, Person> peopleMap;

	peopleMap[0] = Person("Mike", 40);
	peopleMap[8] = Person("Raj", 25);
	peopleMap[5] = Person("Vicky", 30);

	cout << "Key    Value" << endl;
	cout << "------------" << endl;
	map<int, Person>::iterator itr;
	for(itr = peopleMap.begin(); itr!=peopleMap.end(); itr++){
		cout << (itr->first) << "      " << flush;
		(itr->second).printMap();
	}

	return 0;
}