#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string>GetString();


int main(){
	size_t size = 10;
	vector<int> vec0; //declare an empty vector
	vector<int> vec1(size); //declare a vector of size 10 with all values as 0
	vector<int> vec2(size, 99); //declare a vector of size 10 with all values as 99
	for(unsigned int i=0; i<size; i++){
		vec1[i] = i;
		vec2[i] = vec2[i]+i;
	}
	cout << "vec1[1] is " << vec1[1] << endl;
	cout << "vec2[1] is " << vec2[1] << endl;

	//initialize a vector like array
	vector<double> vec3{1.1, 2.2, 3.3}; 
	//initialize a vector from another vector
	vector<double> vec4( vec3.begin(), vec3.end()); 
	
	cout << "vec3 is ...";
	for (double x : vec3){
		cout << x << " ";
	}
	cout << endl;

	cout << "vec4 is ...";
	for (double x : vec4){
		cout << x << " ";
	}
	cout << endl << endl;



	//function returns vector
	vector<string> mystrings =GetString();
	cout << mystrings[0] << endl;
	
	return 0;
}


vector<string> GetString(){
	vector<string> str;
	str.push_back("One");
	str.push_back("Two");
	str.push_back("Three");
	return str;
}