#include <bits/stdc++.h>
using namespace std;

///Description: you are a traveler on a 2D grid. You begin in the top-left
///corner and goal is to travel to the bottom-right corner. 
///You may only move down or right. 

//How many ways can you travel to the goal on a grid with dimensions
//m*n?



//recursive version
//Time: O(2^(n+m))
//Space: O(n+m)
int gridTraveler(int m, int n){
	
	if(m==1 and n==1) return 1;
	if(m==0 or n==0) return 0;
	
	
	return gridTraveler(m-1, n) + gridTraveler(m, n-1);
}


//recursion with memo
//Time: O(n*m)
//Space: O(n+m)
long long gridTravelerMemorization(int m, int n, vector<vector<long long>> &memo){
	
	if(m==1 and n==1) return 1;
	if(m==0 or n==0) return 0;
	
	if(memo[m][n]!=-1) return memo[m][n];
	
	memo[m][n] = gridTravelerMemorization(m-1, n, memo) + gridTravelerMemorization(m, n-1, memo);
	return memo[m][n];
}


//tabulation method: iterative
//Time: O(m*n) == O(row*col) 
//Space: O(m*n)
long long gridTravelerTabulation(int m, int n){
	
	vector<vector<long long>> dp(m+1, vector<long long> (n+1, 0));
	
	dp[1][1] = 1;
	
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			long long current = dp[i][j];
			if(i+1<=m) dp[i+1][j] +=current;
			if(j+1<=n) dp[i][j+1] +=current;
		}
	}
	
	return dp[m][n];
}



int main(){
	
	cout<<gridTraveler(1, 1)<<endl; //1
	cout<<gridTraveler(2, 3)<<endl; //3
	cout<<gridTraveler(3, 2)<<endl; //3
	cout<<gridTraveler(3, 3)<<endl; //6
	
	
	vector<vector<long long>> memo(100, vector<long long> (100, -1));
	
	cout<<gridTravelerMemorization(18, 18, memo)<<endl; //2333606220
	cout<<gridTraveler(0, 0)<<endl; //0
	
	cout<<gridTravelerTabulation(20, 25)<<endl;
	
	return 0;
}
