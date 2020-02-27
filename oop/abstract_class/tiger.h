/* *********************************************************
File name:   tiger.h
Author:      Roy T Wu
Description:
********************************************************* */
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