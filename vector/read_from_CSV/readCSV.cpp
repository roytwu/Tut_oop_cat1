//* File name: WorkerCSVReader.cpp
#include "readCSV.h"


//* Constructor Overloading
CSVReader::CSVReader(string& filename, string& delim) {
	ms_fileName = filename;
	ms_delimeter = delim;
}

//* Parses through csv file line by line and returns the data in vector of vector of strings  
vector< vector<string> > CSVReader::getData() {
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
	}
	else {
		cout << "Could not open file " << ms_fileName << endl;
	}


	return dataList;
}


//* Parses through csv file line by line and returns the data in vector of vector IMUData
vector<IMUData> CSVReader::getData2() {
	ifstream o_inFile;
	o_inFile.open(ms_fileName);

	vector<IMUData> v_dataList;

	string line;

	if (o_inFile.is_open()) {
		while (getline(o_inFile, line)) {
			vector<string> v_str;
			boost::algorithm::split(v_str, line, boost::algorithm::is_any_of(ms_delimeter));
			IMUData o_imuData(v_str); //use overloaded constructor

			v_dataList.push_back(o_imuData);
		}
		o_inFile.close();
	}
	else {
		cout << "Could not open file " << ms_fileName << endl;
	}


	return v_dataList;
}



vector<double> CSVReader::convertStrToDou(vector<string> svec) {
	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); ++iter) {
		vector<double> dvec;
		string element = *iter;
		double result = std::stod(element);

		//* use a stringstream to get a double value:
		//std::istringstream ctype::is(element);
		//double result;
		//is >> result;


		//* add the double value to the result vector:
		dvec.push_back(result);
		return dvec;
	}
}