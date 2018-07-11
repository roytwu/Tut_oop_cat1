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
	int m_animalID;
	
public:
	Animal();                //no-argument constructor
	Animal(int m_animalID);  //parameterized contstructor

	void speak();
	void info();
};



#endif //ANIMAK_H_