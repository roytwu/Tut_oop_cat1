#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::ofstream;

int main(){
	cout << "Program starts here....." << endl;
	
	ofstream outFile;
	string fileName = "demoTextFile.txt";
	outFile.open(fileName);

	if(outFile.is_open()){
		outFile << "Go Go Power Rangers!!!" << endl;
		outFile << 12345 << endl;
		outFile.close();
	} else{
		cout << "Could not create file: " << fileName << endl;
	}

	return 0;
}