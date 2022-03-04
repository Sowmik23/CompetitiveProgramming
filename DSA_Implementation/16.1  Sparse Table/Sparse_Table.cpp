#include <bits/stdc++.h>
using namespace std;

/*
 * Definitions: 
 * Sparse table is a data structure that allows answering queries of 
 * finding minimum or maximum or gcd in a range in an array in O(1)
 * time after O(nlogn) pre-processing
 * 
 * 
 * 
 * Applications:
 * when you need to answer a lot of queries from a static(unchanged data)
 * array of finding the maximum or the minimum or gcd in a range
 * 
 * 
 * Bellow implementation is for:
 * Range Minimum Queries(RMQ)
 */


const int MAX_N = 105009;
const int MAX_LOG = 20;

vector<int> logs(MAX_N, 0); //logs[i] keeps max p such tha 2^p<=i
vector<vector<int>> table(MAX_LOG, vector<int> (MAX_N, 0));


void computeLogs(int n){
	logs[1] = 0;
	for(int i=2;i<=n;i++){
		logs[i] = logs[i/2]+1;
		//cout<<logs[i]<<" "<<i<<endl;
	}
}

void buildSparseTable(vector<int> &nums, int n){
	for(int i=0;i<=logs[n];i++){
		int currLen = 1<<i; //2^i
		for(int j=0;j+currLen<=n;j++){
			if(currLen==1) table[i][j] = nums[j];
			else {
				table[i][j] = min(table[i-1][j], table[i-1][j+(currLen/2)]);
			}
		}
	}
}


int getMin(int l, int r){
	int p = logs[r-l+1];
	int plen = 1<<p; //2^p
	
	return min(table[p][l], table[p][r-plen+1]);
}


int main(){
	
	vector<int> nums = {1, 3, 5, 7, 9, 11};
	int n = nums.size();
	
	computeLogs(n);
	buildSparseTable(nums, n);
	
	int l = 1;
	int r = 4;
	
	cout<<getMin(l, r)<<endl;
	
	return 0;
}
