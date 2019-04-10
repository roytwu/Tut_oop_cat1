//* File name:   main.cpp
//* Developer:   Roy T Wu
//* Description: Demonstrate <numeric> header       

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::cout; 
using std::endl;
using std::string; 

double myFunc1(double x, double y)
{   
	return x + y;
}

double myFunc2(double x, double y)
{
	double dt = 0.01;
	double result = x + y*dt;
	return result;
}

int main()
{
	//* summation of double, note that the initial value must be double
	std::vector<double> v_foo{ 1.01, 1., 1., 1., 1., 1., 1., 1., 1., 1. };
	double sum_foo = std::accumulate(v_foo.begin(), v_foo.end(), 0.);  
	cout << sum_foo << endl;

	//* sum_foo1 is equivalent to sum_foo
	double sum_foo1 = std::accumulate(v_foo.begin(), v_foo.end(), 0., myFunc1);
	cout << sum_foo1 << endl;

	//* applying user-defined funciton, will can be extended to numerical integration
	double sum_foo2 = std::accumulate(v_foo.begin(), v_foo.end(), 0., myFunc2);
	cout << sum_foo2 << endl;

	return 0;
}