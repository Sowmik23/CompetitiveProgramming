#include <bits/stdc++.h>
using namespace std;

// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

bool isSubset(vector<int> &nums, int target, int i){
    if(target==0) return true;
    if(i<0) return false;


    if(nums[i]>target){
        return isSubset(nums, target, i-1);
    }
    return (isSubset(nums, target-nums[i], i-1) or isSubset(nums, target, i-1));
}


// arr.size = 5
//  4 => 3 => 2
//  5 =>
bool isSubsetWithMemo(vector<int> &nums, vector<vector<int>> &memo, int target, int i){
    if(target==0) return true;
    if(i<0) return false;
    if(memo[i][target]!=-1) return memo[i][target];

    if(nums[i]>target) memo[i][target] = isSubsetWithMemo(nums, memo, target, i-1);

    memo[i][target] = (isSubsetWithMemo(nums, memo, target-nums[i], i-1) or isSubsetWithMemo(nums, memo, target, i-1));
    return memo[i][target];
}

bool tabulaton(vector<int> &nums, int target){
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int> (target+1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(nums[i-1]<=target) dp[i][j]  = (dp[i-1][j-nums[i-1]] or dp[i-1][j]);
            else dp[i][j] =  dp[i-1][j];
        }
    }

    return dp[n][target];
}

//tabulaton with optimized memory
bool tabulationWithOptimization(vector<int>&nums, int target){
    int n = nums.size();
    vector<int> dp(target+1);
    dp[0] =  1; //if target ==0 then true;
    for(int i=0;i<n;i++){
        for(int j=target;j>=nums[i];j--){
            if(nums[i]<=target) dp[j] = (dp[j-nums[i]] or dp[j]);
        }
    }
    return dp[target];
}

bool isSubsetSum(vector<int> &nums, int target){

    //recursive
    // return isSubset(nums, target, nums.size()-1);

    //recursion with memoizatioin
    // vector<vector<int>> memo(nums.size()+1, vector<int> (target+1, -1));
    // return isSubsetWithMemo(nums, memo, target, nums.size()-1);

    //tabulaton
    // return tabulaton(nums, target);

    return tabulationWithOptimization(nums, target);
}




int main()
{
    vector<int> nums = {1, 5, 3, 7, 4};
    int target = 9;

    cout<<isSubsetSum(nums, target)<<endl;

    return 0;

//N = len(arr)
//SUM = SUM
// dp = [N+1][SUM+1]  // dp[N][SUM]
// recursive(N,SUM)
}




//Best Practise Code:
bool isSubset(vector<int> &nums, int target, int i){
    if(target==0) return true;
    if(i==0) return false;


    if(nums[i-1]>target){
        return isSubset(nums, target, i-1);
    }
    return (isSubset(nums, target-nums[i-1], i-1) or isSubset(nums, target, i-1));
}


// arr.size = 5
//  4 => 3 => 2
//  5 =>
bool isSubsetWithMemo(vector<int> &nums, vector<vector<int>> &memo, int target, int i){
    if(target==0) return true;
    if(i==0) return false;
    if(memo[i][target]!=-1) return memo[i][target];

    if(nums[i-1]>target) memo[i][target] = isSubsetWithMemo(nums, memo, target, i-1);

    memo[i][target] = (isSubsetWithMemo(nums, memo, target-nums[i-1], i-1) or isSubsetWithMemo(nums, memo, target, i-1));
    return memo[i][target];
}

bool tabulaton(vector<int> &nums, int target){
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int> (target+1));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(nums[i-1]<=target) dp[i][j]  = (dp[i-1][j-nums[i-1]] or dp[i-1][j]);
            else dp[i][j] =  dp[i-1][j];
        }
    }

    return dp[n][target];
}

//tabulaton with optimized memory
bool tabulationWithOptimization(vector<int>&nums, int target){
    int n = nums.size();
    vector<int> dp(target+1);
    dp[0] =  1; //if target ==0 then true;
    for(int i=0;i<n;i++){
        for(int j=target;j>=nums[i];j--){
            if(nums[i]<=target) dp[j] = (dp[j-nums[i]] or dp[j]);
        }
    }
    return dp[target];
}

bool isSubsetSum(vector<int> &nums, int target){

    //recursive
    // return isSubset(nums, target, nums.size());

    //recursion with memoizatioin
    vector<vector<int>> memo(nums.size()+1, vector<int> (target+1, -1));
    return isSubsetWithMemo(nums, memo, target, nums.size());

    //tabulaton
    // return tabulaton(nums, target);

    return tabulationWithOptimization(nums, target);
}




int main()
{
    vector<int> nums = {1, 5, 3, 7, 4};
    int target = 20;

    cout<<isSubsetSum(nums, target)<<endl;

    return 0;

//N = len(arr)
//SUM = SUM
// dp = [N+1][SUM+1]  // dp[N][SUM]
// recursive(N,SUM)
}
