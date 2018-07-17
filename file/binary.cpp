#include <iostream>
#include <string> 
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::ofstream; 
using std::ios;
using std::ifstream; 

#pragma pack(push, 1) //turn of padding

struct Person{
	char name[50];
	int age;
	double height;
};

#pragma pack(pop)



int main(){
	//cout << sizeof(Person) << endl; 

	Person o_someone = {"Frodo", 220, 0.8};
	string fileName = "test.bin";

	//write a binary file 
	ofstream o_outputFile;
	o_outputFile.open(fileName, ios::binary);

	if(o_outputFile.is_open()){
		//o_outputFile.write((char *)&someone, sizeof(Person));
		o_outputFile.write(reinterpret_cast<char *>(&o_someone), sizeof(Person));
		o_outputFile.close();
	} else{
		cout << "Could not create file ... " << fileName << endl;
	}



	//usualy read and write are in different files
	Person o_someoneElse = {};
	ifstream o_inputFile;
	o_inputFile.open(fileName, ios::binary);

	if(o_inputFile.is_open()){
		o_inputFile.read(reinterpret_cast<char *>(&o_someoneElse), sizeof(Person));
		o_inputFile.close();
	} else{
		cout << "Could not read file ... " << fileName << endl;
	}

	cout << o_someoneElse.name << ", ";
	cout << o_someoneElse.age << ", ";
	cout << o_someoneElse.height << ", " << endl;
	return 0;
}