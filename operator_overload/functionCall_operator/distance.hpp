/* *********************************************************
File name:   distance.hpp (overloading function-call operator)
Developer:   Roy Wu
Last upate:  05/20/2019
Description: demo about overloading function-call operator
             approach #1 and approach #2 lead to equivalent result
********************************************************* */

#ifndef DISTANCE
#define DISTANCE

#include <iostream>
using std::cout;
using std::endl;

class Distance {
public:
	//* required constructors
	Distance() {
		m_feet = 0;
		m_inches = 0;
	}

	//* constructor overload
	Distance(int f, int i) {
		m_feet = f;
		m_inches = i;
	}


	//* overload function call - apporach #1 
	Distance operator()(int a) {
		Distance o_D;
		o_D.m_feet = m_feet*a + (m_inches*a / 12);
		o_D.m_inches = (m_inches*a) % 12;
		return o_D;
	}

	////* overload function call - apporach #2
	//Distance & operator()(int a) {
	//	m_feet = m_feet*a + (m_inches*a / 12);
	//	m_inches = (m_inches*a) % 12;
	//	return *this;
	//}


	//* method to display distance
	void displayDistance() 
	{
		cout << m_feet << "' " <<  m_inches << "\" " << endl;
	}

private:
	int m_feet;     //* 0 to infinite
	int m_inches;   //* 0 to 12
};


#endif //*DISTANCE
