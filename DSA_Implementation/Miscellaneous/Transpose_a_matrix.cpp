#include <bits/stdc++.h>
using namespace std;

/*
1 2 3
4 5 6


4 1
5 2
6 3
*/


void transpose(vector<vector<int>> nums){
	
	int n = nums.size();
	int m = nums[0].size();
	vector<vector<int>> res(m, vector<int> (n));
	
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			//cout<<nums[j][i]<<" ";
			
			res[i][j] = nums[j][i];
		}
	//	cout<<endl;
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
		


int main(){
	
	vector<vector<int>> nums {
		{1, 2, 3},
		{4, 5, 6}
		};
	
	transpose(nums);
	
	
	
	return 0;
}
