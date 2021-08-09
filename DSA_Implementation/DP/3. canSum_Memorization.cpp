#include <bits/stdc++.h>
using namespace std;

///Write a function 'canSum(nums, targetSum)' that takes in a targetSum
///and an array of numbers as arguments.

///The function should return a boolean indicating whether or not it is 
///possible to generate the targetSum using numbers from the array.

///You may use an element of the array as many times as needed.
///You may assume that all input numbers are non-negative.

//Ex. canSum([5, 3, 4, 7], 7) ----> true
//Ex. canSum([2, 4], 7) ----> false;


//recursion
//Time: O(n^m) m: height of the tree
//Space: O(m)
bool canSum(vector<int> &nums, int targetSum){
	
	
	if(targetSum==0) return true;
	if(targetSum<0) return false;
	
	for(int i=0;i<nums.size();i++){
		int remainder = targetSum - nums[i];
		if(canSum(nums, remainder)==true){
			return true;
		}
	}
	return false;
}

//recursion with memorization
//Time: O(m*n)
//Space: O(m)
bool canSumWithMemorization(vector<int> &nums, int targetSum, vector<bool> &memo){
	
	
	if(targetSum==0) return true;
	if(targetSum<0) return false;;
	
	if(memo[targetSum]==true) return memo[targetSum];
	
	for(int i=0;i<nums.size();i++){
		int remainder = targetSum - nums[i];
		if(canSumWithMemorization(nums, remainder, memo)==true){
			memo[targetSum] = true;
			return true;
		}
	}
	memo[targetSum] = false;
	return false;
}



//tabulation method: iterative
//Time: O(m*n) == O(row*col) 
//Space: O(m)
bool canSumWithTabulation(vector<int> &nums, int targetSum){
	
	vector<bool> dp(targetSum+1, false);
	
	dp[0] = true; ///base case
	
	for(int i=0;i<=targetSum;i++){
		if(dp[i]==true){
			for(int j=0;j<nums.size();j++){
				dp[i+nums[j]] = true;
			}
		}
	}
	return dp[targetSum];
}



int main(){
	
	int targetSum;
	vector<int> nums;
	vector<bool> memo(100, false);
	nums = {2, 3};
	targetSum = 7;
	cout<<canSum(nums, targetSum)<<endl;  //true

	memo = vector<bool> (100, false);
	nums = {5, 3, 4, 7};
	targetSum = 7;
	cout<<canSum(nums, targetSum)<<endl; //true
	
	
	memo = vector<bool> (100, false);
	nums = {2, 4};
	targetSum = 7;
	cout<<canSumWithMemorization(nums, targetSum, memo)<<endl; //false
	
	
	memo = vector<bool> (100, false);
	nums = {2, 3, 5};
	targetSum = 8;
	cout<<canSumWithMemorization(nums, targetSum, memo)<<endl; //true
	
	
	memo = vector<bool> (305, false);
	nums = {7, 14};
	targetSum = 300;  //though memorization it takes some time.
	//cout<<canSumWithMemorization(nums, targetSum, memo)<<endl; //false
	
	nums = {7, 14};
	targetSum = 300;
	cout<<canSumWithTabulation(nums, targetSum)<<endl; //false
		
	nums = {2, 4};
	cout<<canSumWithTabulation(nums, 7)<<endl;
		
	
	return 0;
}
