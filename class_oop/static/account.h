#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Account {
public:
	//* member functions can use static members directly, without the scope operator
	void calculate() { amount += amount + rate; }

	static double findRate() { return rate; }
	//static void findRate(double);

private:
	string owner;
	double amount = 100;

	static double rate;
	static double initRate();

};

//* class refernce
Account & ref_a();



#endif
