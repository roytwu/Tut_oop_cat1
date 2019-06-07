/* *********************************************************
File name:   main.cpp (_vtkBasic)
Programmer:  Roy Wu
Description: first program of VTK 
********************************************************* */


//#include <array>               //* std::array
#include <iostream>
#include <string>
#include <vtkMath.h>
#include <vtkPoints.h>
#include <vtkSmartPointer.h>

using std::cout; 
using std::endl;
using std::string; 


int main()
{
	/* --- vtkMath --- */ cout << "----- vtkPMath ----- \n";
	//* create a few points.
	double p0[3] = { 0.0, 0.0, 0.0 };
	double p1[3] = { 1.0, 1.0, 1.3 };
	double p2[3] = { 2.0, 2.9, 2.0 };

	//* find the squared distance between the points.
	double squaredDistance = vtkMath::Distance2BetweenPoints(p0, p1);

	//* take the square root to get the Euclidean distance between the points.
	double distance = sqrt(squaredDistance);

	//* output the results.
	cout << "SquaredDistance = " << squaredDistance << endl;
	cout << "Distance = " << distance << endl;


	/* --- vtkPoints --- */ cout << "\n----- vtkPoints ----- \n";
	//* smartPointer way to create and object
	//* vtkPoints can be think as std::vector<cv::Point3d>
	vtkSmartPointer<vtkPoints> vt_pts = vtkSmartPointer<vtkPoints>::New();
	
	//* insert vtkPoint to container,
	//* which is similar to std::vector::push_back()
	vtkIdType id_pts[3];
	id_pts[0] = vt_pts->InsertNextPoint(p0);
	id_pts[1] = vt_pts->InsertNextPoint(p1);
	id_pts[2] = vt_pts->InsertNextPoint(p2);
	
	double tempArr[3];             //* C-style array of double
	vt_pts->GetPoint(2, tempArr);  //* copy vtkPoint component to another C-style array

	//* loop through the elements of the C-style array
	size_t n = sizeof(tempArr) / sizeof(tempArr[0]);
	for (size_t i = 0; i < n; i++) {
		cout << tempArr[i] << " ";
	}
	cout << endl;
	

	return 0;
}