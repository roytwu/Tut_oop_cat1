/* *********************************************************
File name:   main.cpp (_inheritance)
Author:      Roy Wu
Description: Demo about inheritance
********************************************************* */
#include <iostream>
#include <memory>
#include "animal.h"
#include "cat.h"
#include "tiger.h"
//using std::cout;
//using std::endl;

// //Return objects from functions
// Cat *createCat(){
// 	Cat *op_Cat = new Cat();
// 	op_Cat->makeAngry();
// 	return op_Cat;
// }

int main(){
	//cout << "----- Super class 'Animal' -----\n";
	//Animal o_am(99);
	//o_am.speak();
	//o_am.info();
	////o_am.jump(); //* error!! Animal can't access its child class


	//cout << "\n\n----- Sub class 'Cat' -----\n";
	//Cat *op_tom = new Cat(); 
	//op_tom->m_happy = true;
	//op_tom->speak();          //*Cat can do what Animal can do
	//op_tom->jump();
	//delete op_tom;

	//cout << endl;
	//Cat *op_kitty = new Cat(108);
	//op_kitty->info();
	//delete op_kitty;


	cout << "\n\n----- Sub-sub class 'Tiger' -----\n";
	std::shared_ptr<Tiger> o_bengal(new Tiger);
	//Tiger *op_bengal = new Tiger();
	o_bengal->info();
	o_bengal->speak();  //* Tiger can do what Animal can do
	o_bengal->jump();   //* Tiger can do what Cat can do
	o_bengal->attackAntelope();
	//delete op_bengal;

	
	cout << endl << "\n\n----- Polymorphism -----\n";
	Animal *op_animal = new Cat;  
	op_animal->speak();
	delete op_animal;


    cout << "\nEnding porgram..." << endl;
	return 0;
}


/*
  ---------------------------------
  super-calss      Animal  
  ---------------------------------               
  sub-class          |--> Cat
  ---------------------------------
  sub-sub-class        |--> Tiger
  ---------------------------------

*/