#include <iostream>
#include <string> //getline()
#include <fstream> //fstream, ofstream, ios
using std::cout;
using std::endl;
using std::string;
using std::ofstream; 
using std::fstream;
using std::ios;
using std::ifstream; 

int main(){	
	string fileName1 = "demoFile1.txt";
	string fileName2 = "demoFile2.txt";

	//write text files
	ofstream outFile1; //outFile1 is an output_file_stream object
	fstream  outFile2;

	outFile1.open(fileName1);
	outFile2.open(fileName2, ios::out);  //see Note for reference

	if(outFile1.is_open()){
		outFile1 << "Writing file with ofstream!" << endl;
		outFile1 << 12345 << endl;
		outFile1 << "This is the third line." << endl;
		outFile1.close();
	} else{
		cout << "Could not create file: " << fileName1 << endl;
	}


	if(outFile2.is_open()){
		outFile2 << "Write file with fstream..." << endl;
		outFile2 << 999.99 << endl;
		outFile2 << "Go go power rangers!!" << endl;
		outFile2.close();
	} else{
		cout << "Could not create file: " << fileName2 << endl;
	}


	//read text files
	//ifstream: input stream class to operate on files
	ifstream o_inFile1; //o_inFile1 is an object of class ifstream
	ifstream o_inFile2;
	o_inFile1.open(fileName1);
	o_inFile2.open(fileName2);

	if(o_inFile1.is_open()){
		string line;
		//inFile >> line;

		while(!o_inFile1.eof())
		{
			getline(o_inFile1, line);
			cout << line << endl;
		}
		o_inFile1.close();
	} else{
		cout << "Could not open file " << fileName1 << endl;
	}


	if(o_inFile2.is_open()){
		string line;
		while(o_inFile2)  //equivalent to while(!inFile2.eof())
		{
			getline(o_inFile2, line);
			cout << line << endl;
		}
		o_inFile2.close();
	} else{
		cout << "Could not open file " << fileName2 << endl;
	}


	//parse a text file
	string fileName3 = "demo.txt";
	ifstream o_input;
	o_input.open(fileName3);

	if(!o_input.is_open()){
		return 1;
	}

	while(o_input){
		string line;
		int population;

		getline(o_input, line, ':');
		o_input >> population; //reading directly from the stream
		//o_input.get();    //C++98
		o_input  >> std::ws; //ws is used to extract whitespaces, C++11
		if(!o_input){
			break;
		}
		cout << line << " ---> " << population << endl;
	}
	o_input.close();


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