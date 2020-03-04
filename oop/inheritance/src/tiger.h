/* *********************************************************
Author:      Roy T Wu
Description: sub-sub-class
********************************************************* */
#ifndef TIGER_H_
#define TIGER_H_
#include <iostream>
#include "cat.h"
using std::cout;
using std::endl;

class Tiger: public Cat
{
public:
	Tiger();
	~Tiger();

	void attackAntelope();
};
#endif //* TIGER_H_