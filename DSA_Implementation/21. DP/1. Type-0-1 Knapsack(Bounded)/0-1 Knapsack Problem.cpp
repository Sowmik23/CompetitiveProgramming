/// 0-1 Knapsack Problem
// Problem Statement- Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

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

//Tabulation
int tabulation(vector<int> &weights, vector<int> &values, int W){
	//define the matrix first
	int n = weights.size();
	int dp[n+1][W+1];
	//initialize the first row and first column with base case value:n==0 and W==0 then 0
	for(int i=0;i<n;i++){
		for(int j=0;j<W;j++){
    		if(i==0 or j==0) dp[i][j] = 0;
    	}
	}


	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(weights[i]<=W){
				dp[i][j] = max(values[i]+dp[i-1][j-weights[i]], dp[i-1][j]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][W];
}


int knapsack(int wt[], int val[], int n, int w) {
    if(n == 0 or w == 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];

    if(wt[n-1] > w)
        return dp[n][w] = knapsack(wt, val, n-1, w);

    return dp[n][w] = max(knapsack(wt, val, n-1, w-wt[n-1]) + val[n-1], knapsack(wt, val, n-1, w));
}


//tabulation with optimized memory
int knapsack(int wt[], int val[], int n, int w) {
    int dp[w+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        for(int j = w; j >= wt[i]; j--){
            dp[j] = max(dp[j], dp[j-wt[i]] + val[i]);
        }
    }
    return dp[w];
}



// Similar Problems-
// Subset sum
// Equal sum partition
// Count of subsets sum with a given sum
// Minimum subset sum difference
// Count the number of subset with a given difference
// Target sum


int main(){

	vector<int> weights = {10, 20, 30};
	vector<int> values = {60, 100, 120};
	int W = 50;

	int n = weights.size();

	//with recursion
	cout<<dpKnapsack(weights, values, W, n)<<endl;


	//with memoization
	vector<vector<int>> memo(n+1, vector<int> (W+1, -1));

	cout<<dpMemoization(weights, values, memo, W, n-1)<<endl;

	//tabulation
	cout<<tabulation(weghts, values, memo, W)<<endl;


	return 0;
}
