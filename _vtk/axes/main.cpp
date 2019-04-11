//* File name:   main.cpp
//* Developer:   Roy T Wu
//* Description: first program about VTK   
//*              code origin: https://lorensen.github.io/VTKExamples/site/Cxx/GeometricObjects/Axes/
                
#include <iostream>
#include <string>

#include <vtkActor.h>
#include <vtkAxesActor.h>
#include <vtkCamera.h>
#include <vtkCaptionActor2D.h>
#include <vtkNamedColors.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkTextProperty.h>
#include <vtkTransform.h>

using std::cout; 
using std::endl; 

int main()
{
	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

	//* ----- create sphere source -----
	vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
	sphere->SetCenter(0.0, 0.0, 0.0);
	sphere->SetRadius(0.5);

	//* create a mapper
	vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	sphereMapper->SetInputConnection(sphere->GetOutputPort());

	//* create an actor
	vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
	sphereActor->SetMapper(sphereMapper);

	//* renderer and render window
	vtkSmartPointer<vtkRenderer> renderer1 = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> rWindow = vtkSmartPointer<vtkRenderWindow>::New();
	rWindow -> SetWindowName("window_axes");
	rWindow -> AddRenderer(renderer1);
	rWindow -> SetSize(800, 500);

	//* create an interactor, providing interaction for mouse/key/time events
	vtkSmartPointer<vtkRenderWindowInteractor>rWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	rWindowInteractor->SetRenderWindow(rWindow);

	

	//* ----- creating axes -----
	vtkSmartPointer<vtkAxesActor> axes = vtkSmartPointer<vtkAxesActor>::New();

	vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New();
	transform->Translate(1., 0., 0.);

 	//* The axes are positioned with a user transform
	axes->SetUserTransform(transform);

	//* this sets the x axis label to black
	axes->GetXAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(0, 0, 0);

	//* the actual text of the axis label can be changed:
	axes->SetYAxisLabelText("yy");

	//* ----- renderer -----
	//* set background color
	//renderer->SetBackground(colors->GetColor3d("SlateGray").GetData());
	renderer1->SetBackground(colors->GetColor3d("Peru").GetData());

	//* add the actors to the scene
	renderer1->AddActor(sphereActor);
	renderer1->AddActor(axes);

	//* get the cuurrent camera
	renderer1->GetActiveCamera()->Azimuth(50);
	renderer1->GetActiveCamera()->Elevation(-30);
	
	//* automatically set up the camera on the visible actors
	renderer1->ResetCamera();
	
	rWindow->Render();

	//* start the event loop
	//* use start() to replace user-defined event loop. User-defined event loop can still be aplied 
	rWindowInteractor->Start();

	return 0;
}