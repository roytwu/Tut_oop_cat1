#include <iostream>
#include <vector>
#include <chrono>
using std::cout;
using std::endl;
using std::string;
using std::vector;

using hClock   = std::chrono::high_resolution_clock;
using muSec = std::chrono::microseconds;


class Solution{
public:	
	int uniquePaths_A(int m, int n){
		vector< vector<int> > path(m, vector<int>(n,1));
		for(int i=1; i<m; i++){
			for(int j=1; j<n; j++)
				path[i][j] = path[i-1][j] +path[i][j-1];
		}	
		return path[m-1][n-1];
	}

	int uniquePaths_B(int m, int n){
		if(m>n) return uniquePaths_B(n,m);

		vector<int> pre(m,1);
		vector<int> cur(m,1);
		for(int j=1; j<n; j++){
			for(int i=1; i<m; i++)
				cur[i] =cur[i-1] + pre[i];
			
			swap(pre,cur);
		}
		return pre[m-1];
	}
};




int main(){
	Solution o_solu1;
	
	auto t1 = hClock::now();
	cout << o_solu1.uniquePaths_A(70, 30) << endl;
	auto t2 = hClock::now();
	cout << "run time: ";	
	cout << std::chrono::duration_cast<muSec> (t2-t1).count();
	cout << " micro-seconds" <<endl;

	auto t3 = hClock::now();
	cout << o_solu1.uniquePaths_A(70, 30) << endl;
	auto t4 = hClock::now();
	cout << "run time: ";	
	cout << std::chrono::duration_cast<muSec> (t4-t3).count();
	cout << " micro-seconds" <<endl;


	return 0;
}