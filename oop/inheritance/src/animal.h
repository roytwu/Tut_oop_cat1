/* *********************************************************
Author:      Roy Wu
Description: super class
********************************************************* */
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
	Animal();                //* no-argument constructor
	Animal(int m_animalID);  //* parameterized contstructor
	virtual ~Animal();       //* make destructor virtual for polymorphism

	virtual void speak();    //* virtual for polymorphism
	void info();
};

#endif //ANIMAK_H_