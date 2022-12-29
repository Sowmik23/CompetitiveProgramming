// Problem Description: Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.
#include <bits/stdc++.h>
using namespace std;


int recursive(vector<int> &nums, int k, int i){
    if(k==0) return 1;
    if(i==0) return 0;

    int x = 0;
    if(nums[i-1]<=k) x+=recursive(nums, k-nums[i-1], i-1);
    x+=recursive(nums, k, i-1);
    return x;
}

int recursionWithMemoization(vector<int> &nums, vector<vector<int>> &memo, int k, int i){
    if(k==0) return 1;
    if(i==0) return 0;
    if(memo[i-1][k]!=0) return memo[i-1][k];

    if(nums[i-1]<=k) memo[i-1][k]+=recursionWithMemoization(nums, memo, k-nums[i-1], i-1);
    memo[i-1][k]+=recursionWithMemoization(nums, memo, k, i-1);
    return memo[i-1][k];
}

int countSubsetWithSumX(vector<int> &nums, int k){

    //recursion
    // return recursive(nums, k, nums.size());

    //recursion with memoization
    // vector<vector<int>> memo(nums.size(), vector<int> (k+1, 0));
    // return recursionWithMemoization(nums, memo, k, nums.size());

    //tabulation
    /*
    vector<vector<int>> dp(nums.size()+1, vector<int>(k+1, 0));
    for(int i=0;i<nums.size();i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=nums.size();i++){
        for(int j=0;j<=k;j++){
            if(nums[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[nums.size()][k];
    */
    
    //space optimization
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    for(int i=0;i<nums.size();i++){
        for(int j=k;j>=nums[i];j--){
            if(nums[i]<=j) dp[j] = dp[j] + dp[j-nums[i]];
            else dp[j] = dp[j];
        }
    }
    return dp[k];
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    int k = 6;
    cout<<countSubsetWithSumX(nums, k)<<endl;

    nums = {1, 1, 1, 1};
    k = 1;
    cout<<countSubsetWithSumX(nums, k)<<endl;

    nums = {2, 3, 5, 6, 8, 10};
    k = 10;

    cout<<countSubsetWithSumX(nums, k)<<endl;

    return 0;
}
