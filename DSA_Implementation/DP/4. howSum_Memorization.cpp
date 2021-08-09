#include <bits/stdc++.h>
using namespace std;

///Write a function 'howSum(targetSum, nums)' that takes in a targetSum
///and an array of numbers as arguments
///The function should return an array containing any combination of elements
///that add up to exactly the targetSum. If there is no combination that
///adds up to the targetSum, then return null.

///If there are multiple combinations possible, you may return any 
///single one.

//recursion
//Time: O(n^m *m) , m = targetSum, n = numbers.size()
//Space: O(m)

vector<int> res;
	
bool howSum(vector<int> &nums, int targetSum){
	if(targetSum==0) return true;
	if(targetSum<0) return false;
	
	for(int i=0;i<nums.size();i++){
		int remainder = targetSum - nums[i];
		
		if(howSum(nums, remainder)==true) {
			res.push_back(nums[i]);
			return true;
		}
	}
	
	return false;
}

//recursion with memorization
//Time:
//Space:
bool howSumWithMemorization(vector<int> &nums, int targetSum, vector<bool> &memo){
	if(targetSum==0) return true;
	if(targetSum<0) return false;
	
	if(memo[targetSum]==true) return memo[targetSum];
	//if(memo[targetSum]==false) return memo[targetSum];
	
	for(int i=0;i<nums.size();i++){
		int remainder = targetSum - nums[i];
		
		if(howSum(nums, remainder)==true) {
			res.push_back(nums[i]);
			memo[remainder] = true;
			return true;
		}
	}
	
	return false;
}




//tabulation method: iterative
//Time: O(m^2*n) ==>m = targetSum, n = nums.size() 
//Space: O(m^2)
/*bool howSum(vector<int> &nums, int targetSum){
	
	//need to fix code part and convert into c++;
	vector<vector<int>> dp(targetSum+1, vector<int> (targetSum+1, NULL));
	
	dp[0] = [];
	
	for(int i=0;i<nums.size();i++){
		if(dp[i]!=NULL){
			for(int j=0;j<nums.size();j++){
				dp[i+nums[j]] = ...table[i], nums[i]
			}
		}
	}
	
	return dp[targetSum];
}
*/


int main(){
	
	vector<int> nums;
	int targetSum ;
	
	nums = {2, 3};
	targetSum = 7;
	howSum(nums, targetSum);
	for(auto i: res) cout<<i<<" ";
	cout<<endl; 
	
	res = vector<int> ();
	nums = {5, 3, 4, 7};
	targetSum = 7;
	howSum(nums, targetSum);
	for(auto i: res) cout<<i<<" ";
	cout<<endl; 
	
	
	
	res = vector<int> ();
	nums = {2, 4};
	targetSum = 10;
	howSum(nums, targetSum);
	for(auto i: res) cout<<i<<" ";
	cout<<endl; 
	
	
	res = vector<int> ();
	nums = {2, 3, 5};
	targetSum = 8;
	howSum(nums, targetSum);
	for(auto i: res) cout<<i<<" ";
	cout<<endl; 
	
	res = vector<int> ();
	nums = { 3, 5, 2};
	targetSum = 8;
	vector<bool> memo(100, false);
	howSumWithMemorization(nums, targetSum, memo);
	for(auto i: res) cout<<i<<" ";
	cout<<endl; 
	
	memo = vector<bool> (310, false);
	res = vector<int> ();
	nums = {7, 14};
	targetSum = 84;
	howSumWithMemorization(nums, targetSum, memo);
	for(auto i: res) cout<<i<<" ";
	cout<<endl; 
	
	
	return 0;
}
