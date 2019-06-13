/* *********************************************************
File name:   main.cpp (_polyData)
Programmer:  Roy Wu
Description: example of vtkPolyData 
********************************************************* */

//#include <array>               //* std::array
#include <iostream>
#include <string>
#include <vtkDoubleArray.h>
#include <vtkMath.h>
#include <vtkPoints.h>
#include <vtkPointData.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>

using std::cout; 
using std::endl;
using std::string; 

void ManualMethod(vtkPolyData* input);


int main()
{
	vtkSmartPointer<vtkSphereSource> sphereSource = vtkSmartPointer<vtkSphereSource>::New();
	sphereSource->Update();

	vtkPolyData* polydata = sphereSource->GetOutput();

	vtkSmartPointer<vtkDoubleArray> doubles = vtkSmartPointer<vtkDoubleArray>::New();
	doubles->SetName("Doubles");
	doubles->SetNumberOfTuples(polydata->GetNumberOfPoints());

	polydata->GetPointData()->AddArray(doubles);

	vtkSmartPointer<vtkIntArray> ints = vtkSmartPointer<vtkIntArray>::New();
	ints->SetName("Ints");
	ints->SetNumberOfTuples(polydata->GetNumberOfPoints());

	polydata->GetPointData()->AddArray(ints);

	ManualMethod(polydata);

	return 0;
}

void ManualMethod(vtkPolyData* input) 
{
	unsigned int numberOfArr = input->GetPointData()->GetNumberOfArrays();
	std::cout << "There are " << numberOfArr << " arrays." << std::endl;
	
	vtkSmartPointer<vtkPolyData> newPoly = vtkSmartPointer<vtkPolyData>::New();

	for (unsigned int i = 0; i < numberOfArr; i++)
	{
		cout << "array " << i << ":" << std::endl;
		cout << "name: " << input->GetPointData()->GetArrayName(i) << endl;
		cout << "type: " << input->GetPointData()->GetArray(i)->GetDataType() << endl;
		cout << std::endl;

		newPoly->GetPointData()->AddArray(input->GetPointData()->GetArray(i));

		cout << "new polydata... " << std::endl;
		for (unsigned int i = 0; i < numberOfArr; i++)
		{
			cout << "array " << i << ":" << std::endl;
			cout << "name: " << newPoly->GetPointData()->GetArrayName(i) << endl;
			cout << "type: " << newPoly->GetPointData()->GetArray(i)->GetDataType() << endl;
			cout << endl;
		}
	}

}
