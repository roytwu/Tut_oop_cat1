//* File name:   main.cpp
//* Developer:   Roy T Wu
//* Description: first program about VTK   
//*              code origin: https://lorensen.github.io/VTKExamples/site/Cxx/GeometricObjects/Axes/
                
#include <array>
#include <iostream>
#include <string>

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkFloatArray.h>
#include <vtkNamedColors.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>


using std::cout; 
using std::endl; 

int main()
{
	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

	std::array<std::array<double, 3>, 8> pts = { { 
		{ { 0, 0, 0 } },
		{ { 1, 0, 0 } },
		{ { 1, 1, 0 } },
		{ { 0, 1, 0 } },
		{ { 0, 0, 1 } },
		{ { 1, 0, 1 } },
		{ { 1, 1, 1 } },
		{ { 0, 1, 1 } } } };
	
	// The ordering of the corner points on each face.
	std::array<std::array<vtkIdType, 4>, 6> ordering = { { 
		{ { 0, 1, 2, 3 } },
		{ { 4, 5, 6, 7 } },
		{ { 0, 1, 5, 4 } },
		{ { 1, 2, 6, 5 } },
		{ { 2, 3, 7, 6 } },
		{ { 3, 0, 4, 7 } } } };

	// We'll create the building blocks of polydata including data attributes.
	vtkSmartPointer<vtkPolyData>   cube    = vtkSmartPointer<vtkPolyData>::New();
	vtkSmartPointer<vtkPoints>     points  = vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkCellArray>  polys   = vtkSmartPointer<vtkCellArray>::New();
	vtkSmartPointer<vtkFloatArray> scalars = vtkSmartPointer<vtkFloatArray>::New();

	// Load the point, cell, and data attributes.
	for (auto i = 0ul; i < pts.size(); ++i)
	{
		points->InsertPoint(i, pts[i].data());
		scalars->InsertTuple1(i, i);
	}
	for (auto&& i : ordering)
	{
		polys->InsertNextCell(vtkIdType(i.size()), i.data());
	}

	// We now assign the pieces to the vtkPolyData.
	cube->SetPoints(points);
	cube->SetPolys(polys);
	cube->GetPointData()->SetScalars(scalars);

	// Now we'll look at it.
	vtkSmartPointer<vtkPolyDataMapper>cubeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	cubeMapper->SetInputData(cube);
	cubeMapper->SetScalarRange(cube->GetScalarRange());
	vtkSmartPointer<vtkActor> cubeActor = vtkSmartPointer<vtkActor>::New();
	cubeActor->SetMapper(cubeMapper);

	// The usual rendering stuff.
	vtkSmartPointer<vtkCamera> camera = vtkSmartPointer<vtkCamera>::New();
	camera->SetPosition(1, 1, 1);
	camera->SetFocalPoint(0, 0, 0);

	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();
	renWin->AddRenderer(renderer);

	vtkSmartPointer<vtkRenderWindowInteractor> iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	iren->SetRenderWindow(renWin);

	renderer->AddActor(cubeActor);
	renderer->SetActiveCamera(camera);
	renderer->ResetCamera();
	renderer->SetBackground(colors->GetColor3d("Cornsilk").GetData());

	renWin->SetSize(600, 600);

	// interact with data
	renWin->Render();
	iren->Start();
	return 0;
}