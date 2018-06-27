//File name: unique_paths.cpp
//Author: Roy T Wu
/*Goal: count all the possible paths from top left to bottom right of
		a m by n matrix with the constraints that from each cell you
		can only either move only to right or down
*/		

//Both solutions are frome LeetCode

#include <iostream>
#include <vector>
#include <chrono>
using std::cout;
using std::endl;
using std::string;
using std::vector;

using clockType = std::chrono::high_resolution_clock::time_point;
using hClock    = std::chrono::high_resolution_clock;
using muSec     = std::chrono::microseconds;


class Solution{
public:	
	//solution1: unoptimized solution: O(m*n)
	int uniquePaths_A(int m, int n){
		//decalre a m by n 2D vector and initialize all values as 1
		//the number of path to arrive at point (i,j) is denoted as path[i][j]
		//initial condition: path[i][0]=1, path[o][j]=1
		vector< vector<int> > path(m, vector<int>(n,1));

		for(int i=1; i<m; i++){
			for(int j=1; j<n; j++)
				path[i][j] = path[i-1][j] + path[i][j-1];
		}	
		return path[m-1][n-1];
	}
	// for example: m=3, n=4:
	// p[1][1] = p[0][1] + p[1][0] = 1 + 1 = 2
	// p[1][2] = p[0][2] + p[1][1] = 1 + 2 = 3
	// p[1][3] = p[0][3] + p[1][2] = 1 + 3 = 4
	// p[2][1] = p[1][1] + p[2][0] = 2 + 1 = 3
	// p[2][2] = p[1][2] + p[2][1] = 3 + 3 = 6
	// p[2][3] = p[1][3] + p[2][2] = 4 + 6 = 10


	//solution2: O(min(m,n))
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
	// for example: m=3, n=4:
	// j=1
	// cur[1] = cur[0] + pre[1] = 1 + 1 = 2
	// cur[2] = cur[1] + pre[2] = 2 + 1 = 3

	// j=2
	// pre[1] = pre[0] + cur[1] = 1 + 2 = 3
	// pre[2] = pre[1] + cur[2] = 3 + 3 = 6

	// j=3
	// cur[1] = cur[0] + pre[1] = 1 + 3 = 4
	// cur[2] = cur[1] + pre[2] = 4 + 6 = 10

	/*
		 0,0     0,1     0,2      0,3
		          |       |        |
		          .       .        .
		 1,0 --> 1,1 --> 1,2 -->  1,3
		          |       |        |
		          .       .        .
		 2,0 --> 2,1 --> 2,2 -->  2,3
	
	j=1: pre     cur
	---------------------------------- swap
	j=2:         cur	 pre
	---------------------------------- swap
	j=3;                 pre      cur      
	*/

	//solution 3
	int uniquePaths_C(int m, int n){
		if (m ==1 || m==1)
			return 1;
		m--;
		n--;
		if (m<n)
			return uniquePaths_C(n, m);

		long res =1;
		int j=1;
		for(int i=m+1; i<=m+n; i++, j++){
			res *= i;
			res /= j;
		}
		return (int)res;
	}
};


class Runtime{
private:
	clockType m_t1 = hClock::now();
	clockType m_t2 = hClock::now();
public:
	void stopwatch_start(){
		m_t1 = hClock::now();
	}

	void stopwatch_stop(){
		m_t2 = hClock::now();
		cout << "run time: ";	
		cout << std::chrono::duration_cast<muSec> (m_t2-m_t1).count();
		cout << " micro-seconds" << endl << endl;		
	}
};

int main(){

	Solution o_solu1;
	//stopwatch
	auto t1 = hClock::now();

	cout << o_solu1.uniquePaths_A(3, 4) << endl;
	
	auto t2 = hClock::now();
	cout <<"run time: ";	
	cout << std::chrono::duration_cast<muSec> (t2-t1).count();
	cout << " micro-seconds" << endl;

	
	//stowatch
	auto t3 = hClock::now();
	
	cout << o_solu1.uniquePaths_A(3, 4) << endl;
	
	auto t4 = hClock::now();
	
	cout << "run time: ";	
	cout << std::chrono::duration_cast<muSec> (t4-t3).count();
	cout << " micro-seconds" << endl;


	// Solution o_solu;
	// Runtime o_run;
	// o_run.stopwatch_start();
	// cout << endl << o_solu.uniquePaths_A(3, 4) << endl;
	// o_run.stopwatch_stop();
	return 0;
}
