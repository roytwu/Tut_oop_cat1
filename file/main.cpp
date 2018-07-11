#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;
using std::string;

using std::fstream;
using std::ios;


int main(){
	cout << "Program starts here....." << endl;
	
	ofstream outFile1; //output_file_stream
	fstream  outFile2;

	string fileName1 = "demoFile1.txt";
	string fileName2 = "demoFile2.txt";

	outFile1.open(fileName1);
	outFile2.open(fileName2, ios::out);


	if(outFile1.is_open()){
		outFile1 << "Writing file with ofstream!" << endl;
		outFile1 << 12345 << endl;
		outFile1.close();
	} else{
		cout << "Could not create file: " << fileName1 << endl;
	}


	if(outFile2.is_open()){
		outFile2 << "Write file with fstream..." << endl;
		outFile2 << 999.99 << endl;
		outFile2.close();
	} else{
		cout << "Could not create file: " << fileName2 << endl;
	}

	return 0;
}