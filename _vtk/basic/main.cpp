//* File name:   main.cpp
//* Developer:   Roy T Wu
//* Description: first program about VTK    

#include <iostream>
#include <string>
#include <vtkMath.h>
//#include <vtkSmartPointer.h>

using std::cout; 
using std::endl;
using std::string; 



int main()
{
	// Create two points.
	double p0[3] = { 0.0, 0.0, 0.0 };
	double p1[3] = { 1.0, 1.0, 1.0 };

	// Find the squared distance between the points.
	double squaredDistance = vtkMath::Distance2BetweenPoints(p0, p1);

	// Take the square root to get the Euclidean distance between the points.
	double distance = sqrt(squaredDistance);

	// Output the results.
	cout << "SquaredDistance = " << squaredDistance << endl;
	cout << "Distance = " << distance << endl;

	return 0;
}