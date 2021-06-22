#include <bits/stdc++.h>
using namespace std;

/*
1 2 3   
4 5 6

n1 x m1  m2 x n2

4 1
5 2
6 3
*/


void multi(vector<vector<int>> nums1, vector<vector<int>> nums2){
	
	int n1 = nums1.size();
	int m1 = nums1[0].size();
	
	int n2 = nums2.size();
	int m2 = nums2[0].size();
	
	
	vector<vector<int>> res(n1, vector<int> (m2,0));
	
	
	for(int i=0;i<n1;i++){
		for(int j=0;j<m1;j++){
			for(int k=0;k<m2;k++){
				res[i][j] += nums1[i][k]*nums2[k][j];
			}
		}
	//	cout<<endl;
	}
	
	for(int i=0;i<n1;i++){
		for(int j=0;j<m2;j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
		


int main(){
	
	vector<vector<int>> nums1 {
		{1, 2},
		{4, 5}
		};
	
	vector<vector<int>> nums2 {
		{1, 2},
		{3, 4}
		};
	
	multi(nums1, nums2);
	
	
	
	return 0;
}
