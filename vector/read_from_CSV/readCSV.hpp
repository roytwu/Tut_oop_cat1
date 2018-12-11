#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::vector;
using std::ifstream;
using std::getline;

class CSVReader{
public:
	CSVReader(string filename, string delim = ","): fileName(filename), delimeter(delim) {}
	vector< vector<string> > getData(); //function to fetch data from a CSV file
	
private:	
	string fileNmae;
	string delimeter;
};

/* 
Parses through csv file line by line and returns the data in vector of vector of strings  
*/
vector< vector<string> > CSVReader::getData(){
	ifstream o_input;
	o_inpupt.open(fileName);
	
	vector< vector<string> > dataList;
	
	string line;
//	while(getline(o_input, line)){
		
//	}
}