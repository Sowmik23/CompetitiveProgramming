/// 0-1 Knapsack Problem

#include <bits/stdc++.h>
using namespace std;


/// Given weights and values of n items, put these items 
/// in a knapsack of capacity W to get the maximum total value
/// in the knapsack.

/// You cannot break an item, either pick the complete item 
/// or don’t pick it (0-1 property).
/*
weights[] = {10, 20, 30};
values[] = {60, 100, 120};
W = 50;

output: 220
*/


/// Recursion
int dpKnapsack(vector<int> &weights, vector<int> &values, int W, int i){
	
	//base case
	if(i==0 or W==0) return 0;
	
	int x;
	if(W>=weights[i]) {
		x = dpKnapsack(weights, values, W-weights[i], i-1)+values[i]; 
	}
	
	return max(x, dpKnapsack(weights, values, W, i-1));
} 

// Recursion with Memoization
int dpMemoization(vector<int> &weights, vector<int> &values, vector<vector<int>> memo, int W, int i){
	
	if(i==0 or W==0) return 0;
	
	if(memo[i][W]!=-1) return memo[i][W];
	
	int x;
	if(W>=weights[i]){
		x = dpMemoization(weights, values, memo, W-weights[i], i-1)+values[i];
	}
	
	memo[i][W] = max(x, dpMemoization(weights, values, memo, W, i-1));
	
	return memo[i][W];
}


int main(){
	
	vector<int> weights = {10, 20, 30};
	vector<int> values = {60, 100, 120};
	int W = 50;
	
	int n = weights.size();

	//with recursion
	cout<<dpKnapsack(weights, values, W, n-1)<<endl;
	
	
	//with memoization
	vector<vector<int>> memo(n+1, vector<int> (W+1, -1));
	
	cout<<dpMemoization(weights, values, memo, W, n-1)<<endl;
	
	//tabulation
	
	
	
	return 0;
}
