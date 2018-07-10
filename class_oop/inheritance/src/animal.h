//file name: animal.h
//Programmer: Roy T Wu

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
using std::cout;
using std::endl;

//Animal is a super-calss of Cat
class Animal{
public:
	//constructor
	Animal(){
		cout << "--Animal consructor called, Animal created!--" << endl;
	}
	void speak(){ 
		cout << "Grrrrr...." << endl; 
	}
};



#endif //ANIMAK_H_