/* *********************************************************
Author:      Roy Wu
Description: static class members/member funcitons
********************************************************* */
#include "account.h"

//* initialize private static member of class
double Account::rate = 0.01;


//* class reference?
Account & ref_a()
{
	cout << "\nAccess class reference..." << endl;
	Account o_ac;

	return o_ac;
}
