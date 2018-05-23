/*
two boolean variable are defined, "angry" is private and "happy" is public
"happy" can be accessed beyounf the clss 
while "angry" is only avaialbe within the calss
*/
//file name: cat.h
//Programmer: TWu

class Cat{
private:
	/*in class initialization, only in c++11, 1st way to do it*/
	//bool angry = false; 

	bool angry;

public:
	//if constructor is not used, uncomment "bool angry=false;" 
	//and comment out "bool angry;"
	Cat(): angry(false){} /*constructor, 2nd way to initialize angry*/
	//Cat(); /*3rd way to initialize angry, check cat.cpp*/
	~Cat();  //destructor
	

	bool happy;
	void speak();
	void jump();

	void makeAngry();
	void makeSad();

};


