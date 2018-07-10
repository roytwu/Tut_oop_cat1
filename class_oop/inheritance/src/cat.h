//file name: cat.h; header file of cat.cpp
//Programmer: Roy T Wu

#ifndef CAT_H_
#define CAT_H_

#include "animal.h"  //mother class


//Cat is a sub-class of Animal
class Cat: public Animal{
private:
	static int countObject; 
	int m_id;
	bool m_angry;

public:
	Cat(); /*3rd way to initialize angry, check cat.cpp*/
	~Cat();  //destructor
	
	bool m_happy;
	//void speak();
	void jump();

	void makeAngry();
	void makeSad();

	//make "MAX" read-only variable
	static int const MAX = 99;
	int getID();
};


#endif //CAT_H_