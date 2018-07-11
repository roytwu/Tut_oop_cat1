#include <iostream>
#include <string>
#include <fstream> //fstream, ofstream, ios
using std::cout;
using std::endl;
using std::string;
using std::ofstream; 
using std::fstream;
using std::ios;


int main(){
	cout << "Program starts here....." << endl;
	
	ofstream outFile1; //outFile1 is an output_file_stream object
	fstream  outFile2;

	string fileName1 = "demoFile1.txt";
	string fileName2 = "demoFile2.txt";

	outFile1.open(fileName1);
	outFile2.open(fileName2, ios::out);  //see Note for reference


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


/* ----- Note -----
ofstream: output file stream  
	ofstream only has methods for outputting
fstream: input/output file stream class
	fstream can be used for input and output

<fstream>
void open(): open file
void close(): close file
bool is_open(): true if a file is open and associated with the stream 
                object, false otherwise 

open(file_name, mode);
mode is a parameter with a combination of the foloowing flags:
	ios::in              
	ios::out
	ios::binary                
	ios::ate
	ios::app
	ios::trunc
All these flags can be combined using bitwise operator OR(|)
*/