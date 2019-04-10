//* File name:   main.cpp
//* Developer:   Roy T Wu
//* Description: creating mesh grid in VTK  
//*              code origin: https://lorensen.github.io/VTKExamples/site/Cxx/StructuredGrid/BlankPoint/
                
#include <iostream>
#include <string>

#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <vtkIdList.h>
#include <vtkMath.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkStructuredGridGeometryFilter.h>
#include <vtkSmartPointer.h>
#include <vtkStructuredGrid.h>
#include <vtkXMLStructuredGridWriter.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkXMLStructuredGridWriter.h>

using std::cout; 
using std::endl; 

int main()
{
	//* create grid items
	int gridSize = 9;
	int counter = 0;
	vtkSmartPointer<vtkStructuredGrid> structGridXY = vtkSmartPointer<vtkStructuredGrid>::New();
	vtkSmartPointer<vtkPoints> pointsXY = vtkSmartPointer<vtkPoints>::New();

	vtkSmartPointer<vtkStructuredGrid> structGridXZ = vtkSmartPointer<vtkStructuredGrid>::New();
	vtkSmartPointer<vtkPoints> pointsXZ = vtkSmartPointer<vtkPoints>::New();

	//* create grid of points
	for (int j = 0; j < gridSize; j++)
	{
		for (int i = 0; i < gridSize; i++)
		{
			pointsXY->InsertNextPoint(i, j, 0);  //* xy-plane
			pointsXZ->InsertNextPoint(i, 0, j);  //* xz-plane
			counter++;
		}
	}

	//* specify the dimensions of the grid
	structGridXY->SetDimensions(gridSize, gridSize, 1);
	structGridXY->SetPoints(pointsXY);
	//structGridXY->BlankPoint(27);
	structGridXY->Modified();

	structGridXZ->SetDimensions(gridSize, gridSize, 1);
	structGridXZ->SetPoints(pointsXZ);
	structGridXZ->Modified();

	//* create mapper 
	vtkSmartPointer<vtkDataSetMapper> gridMapperXY = vtkSmartPointer<vtkDataSetMapper>::New();
	gridMapperXY->SetInputData(structGridXY);

	vtkSmartPointer<vtkDataSetMapper> gridMapperXZ = vtkSmartPointer<vtkDataSetMapper>::New();
	gridMapperXZ->SetInputData(structGridXZ);


	//* create actor
	vtkSmartPointer<vtkActor> gridActorXY = vtkSmartPointer<vtkActor>::New();
	gridActorXY->SetMapper(gridMapperXY);
	gridActorXY->GetProperty()->EdgeVisibilityOn();
	gridActorXY->GetProperty()->SetEdgeColor(0, 0, 1);
	gridActorXY->GetProperty()->SetColor(0.3, 0.3, 0.3);

	vtkSmartPointer<vtkActor> gridActorXZ = vtkSmartPointer<vtkActor>::New();
	gridActorXZ->SetMapper(gridMapperXZ);
	gridActorXZ->GetProperty()->EdgeVisibilityOn();
	gridActorXZ->GetProperty()->SetEdgeColor(0, 1, 0);
	gridActorXZ->GetProperty()->SetColor(0.3, 0.3, 0.3);


	//* create a renderer, render window, and interactor
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> rWindow  = vtkSmartPointer<vtkRenderWindow>::New();
	rWindow->AddRenderer(renderer);
	rWindow->SetSize(800, 500);
	
	vtkSmartPointer<vtkRenderWindowInteractor> rWindInteractor =vtkSmartPointer<vtkRenderWindowInteractor>::New();
	rWindInteractor->SetRenderWindow(rWindow);


	//* add the actor to the scene
	renderer->AddActor(gridActorXY);
	renderer->AddActor(gridActorXZ);
	renderer->SetBackground(.3, .3, .3); //* background color

	//* render and interact
	rWindow->Render();
	rWindInteractor->Start();

	return 0;
}