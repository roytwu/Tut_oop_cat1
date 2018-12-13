/* file name: readCSV.hpp
*  programmer: Roy T Wu
*  Project: reading data from a CSV file
*  Reference: https://thispointer.com/how-to-read-data-from-a-csv-file-in-c/  */

#ifndef READCSV_H_
#define READCSV_H_

#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::getline;

class CSVReader{
public:
	//* inline member initialization:
	// CSVReader(string filename, string delim = ","): fileName(filename), delimeter(delim) {}
	//* which is equivalent to:
	// CSVReader(string filename, string delim = ","): {fileName=filename; delimeter=delim;}  
	CSVReader(string, string);

	//* function to fetch data from a CSV file
	vector< vector<string> > getData(); 
	
private:	
	string ms_fileName;
	string ms_delimeter;
};


//* Constructor Overloading
CSVReader::CSVReader(string filename, string delim = ",") {
	ms_fileName = filename;  
	ms_delimeter = delim;
}

//* Parses through csv file line by line and returns the data in vector of vector of strings  
vector< vector<string> > CSVReader::getData(){
	ifstream o_inFile;
	o_inFile.open(ms_fileName);
	
	vector< vector<string> > dataList;
	
	string line;

	if (o_inFile.is_open()) {
		while (getline(o_inFile, line)) {
			vector<string> v_foo;
			boost::algorithm::split(v_foo, line, boost::algorithm::is_any_of(ms_delimeter));
			dataList.push_back(v_foo);
		}
		o_inFile.close();
	} else {
		cout << "Could not open file" << ms_fileName << endl;
	}


	return dataList;
}


#endif  //READCSV_H_