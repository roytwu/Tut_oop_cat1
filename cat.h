/*
two boolean variable are defined, "angry" is private and "happy" is public
"happy" can be accessed beyounf the clss 
while "angry" is only avaialbe within the calss
*/
//file name: cat.h
//Programmer: TWu

class Cat{
private:
	//bool angry = false;
	bool angry;

public:
	//if constructor is not used, uncomment "bool angry=false;" 
	//and comment out "bool angry;"
	Cat(): angry(false){} //ctor here 	
	

	bool happy;
	void speak();
	void jump();

	void makeAngry();
	void makeSad();

};


