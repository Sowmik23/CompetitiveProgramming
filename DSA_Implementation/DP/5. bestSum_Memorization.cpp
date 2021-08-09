#include <bits/stdc++.h>
using namespace std;

///Write a function 'bestSum(nums, targetSum)' that takes in a targetSum
///and an array of numbers as arguments

///The function should return an array containing the shortest 
///combination of numbers that add up to exactly the targetSum.
///If there is a tie for the shortest combinartion, you may return any
///of the shortest.

//recursion
vector<int> bestSum(vector<int> &nums, int targetSum){
	if(targetSum==0) return {};
	if(targetSum<0) return null;
	
	vector<int> tmp, res, comb;
	for(auto i: nums){
		int remainder = targetSum-i;
		tmp = bestSum(nums, remainder);
		if(tmp.size()!=0){
			comb = tmp1.push_back(i);
			if(res==NULL or comb.size()< res.size()){
				res = comb;
			}
		}
	}
	
	return tmp1;
}

//recursion with memorization
//Time: 
//Space: 




//tabulation method: iterative
//Time: O(m^2*n) ==>m = targetSum, n = nums.size() 
//Space: O(m^2)
vector<int> bestSumWithTabulation(vector<int> &nums, int targetSum){
	
	vector<int> howSum(vector<int> &nums, int targetSum){
	
	//need to fix code part and convert into c++;
	vector<vector<int>> dp(targetSum+1, vector<int> (targetSum+1, NULL));
	
	dp[0] = [];
	
	for(int i=0;i<nums.size();i++){
		if(dp[i]!=NULL){
			for(int j=0;j<nums.size();j++){
				combination = ...table[i], nums[i];
				if(!dp[i+nums[j]] or dp[i+nums[j]].size()> combination.size()) {
					dp[i+nums[j]] = combination;
				}
			}
		}
	}
	
	return dp[targetSum];
}



int main(){
	
	
	
	return 0;
}
