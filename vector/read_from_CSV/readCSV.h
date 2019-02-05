//* file name:  readCSV.h
//* programmer: Roy T Wu
//* Project:    reading data from a CSV file
//* Reference: https://thispointer.com/how-to-read-data-from-a-csv-file-in-c/  

#ifndef READCSV_H_
#define READCSV_H_

#include <boost/algorithm/string.hpp>
#include <fstream>
#include <locale>
#include "imuData.h"

using std::ifstream;

class CSVReader{
public:
	//* inline member initialization:
	// CSVReader(string filename, string delim = ","): fileName(filename), delimeter(delim) {}
	//* which is equivalent to:
	// CSVReader(string filename, string delim = ","): {fileName=filename; delimeter=delim;}  
	CSVReader(string&,  string&);

	//* function to fetch data from a CSV file
	vector< vector<string> > getData(); 
	vector< IMUData > getData2();
	vector<double> convertStrToDou(vector<string> svec); 

private:	
	string ms_fileName;
	string ms_delimeter;
};





#endif  //READCSV_H_