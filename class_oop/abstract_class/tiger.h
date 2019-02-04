//file name: tiger.h
//Programmer: Roy T Wu

#ifndef TIGER_H_
#define TIGER_H_

#include <iostream>
#include "cat.h"
using std::cout;
using std::endl;

class Tiger: public Cat{
public:
	Tiger();

	void attackAntelope();
};

#endif //TIGER_H_