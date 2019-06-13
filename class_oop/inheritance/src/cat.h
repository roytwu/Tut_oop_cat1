/* *********************************************************
File name:   cat.h (_inheritance)
Programmer:  Roy T Wu
Description: sub-class
********************************************************* */
#ifndef CAT_H_
#define CAT_H_

#include "animal.h"  //* mother class


//* Cat is a sub-class of Animal
class Cat: public Animal{
private:
	static int countObject; 
	int m_id;
	bool m_angry;

public:
	Cat();               //* constructor
	Cat(int m_animalID); //* constructor overload
	~Cat();              //* destructor
	
	bool m_happy;
	void speak();
	void jump();

	void makeAngry();
	void makeSad();

	//*make "MAX" read-only variable
	static int const MAX = 99;
	int getID();
};


#endif //*CAT_H_