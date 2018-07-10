//file name: animal.h
//Programmer: Roy T Wu

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
using std::cout;
using std::endl;

//Animal is a super-calss of Cat
class Animal{
private:
	int m_id;
	
public:
	Animal(); //constructor

	void speak();
};



#endif //ANIMAK_H_