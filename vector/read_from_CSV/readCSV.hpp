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
#include <locale>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::getline;


class IMUData {
public:
	vector<double> m_accel(3);
	vector<double> m_gyro(3);
	vector<double> m_compass(3);
	double m_temptaure;

	friend class CSVReader;
};



class CSVReader{
public:
	//* inline member initialization:
	// CSVReader(string filename, string delim = ","): fileName(filename), delimeter(delim) {}
	//* which is equivalent to:
	// CSVReader(string filename, string delim = ","): {fileName=filename; delimeter=delim;}  
	CSVReader(string, string);

	//* function to fetch data from a CSV file
	vector< vector<string> > getData(); 
	vector< vector<IMUData> > getData2();
	vector<double> convertStrToDou(vector<string> svec); 

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


//* Parses through csv file line by line and returns the data in vector of vector IMUData
vector< vector<IMUData> > CSVReader::getData2() {
	ifstream o_inFile;
	o_inFile.open(ms_fileName);

	vector< vector<IMUData> > dataList;

	string line;

	if (o_inFile.is_open()) {
		while (getline(o_inFile, line)) {
			vector<string> v_str;
			vector<IMUData> v_IMU;
			boost::algorithm::split(v_str, line, boost::algorithm::is_any_of(ms_delimeter));
			dataList.push_back(v_foo);
		}
		o_inFile.close();
	}
	else {
		cout << "Could not open file" << ms_fileName << endl;
	}


	return dataList;
}




vector<double> CSVReader::convertStrToDou( vector<string> svec ) { 
	for (vector<string>::iterator iter = svec.begin(); iter!=svec.end(); ++iter){
		vector<double> dvec;
		string element = *iter;
		double result = std::stod(element);

		//* use a stringstream to get a double value:
		//std::istringstream ctype::is(element);
		//double result;
		//is >> result;


		// add the double value to the result vector:
		dvec.push_back(result);
		return dvec;
	}
}


#endif  //READCSV_H_