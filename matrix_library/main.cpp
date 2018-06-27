#include <iostream>
#include <cstring>
#include "matrx.h"
using namespace std;


int main()
{
	// Declare a 4 by 3 matrix	
	Matrx g(4,3);
	g.printMatrx();

	//	
	double row2[4] = {1, 2, 3};	
	double row4[4] = {10, 0, 10};
	g.adjustRowElements(2, row2);
	g.adjustRowElements(4, row4);
	g.printMatrx();

	cout << "Matrix Transpose: " << endl;
	g.transpose();
	g.printMatrx();

	double d[4][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {0,0,0}}; 
	//cout << sizeof(d[0])/sizeof(double) << endl;		
	double *pTest = &d[0][0];
	g.assignValue(pTest);
	g.printMatrx();



	return 0;
}

