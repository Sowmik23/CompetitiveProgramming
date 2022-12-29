// Count of Subsets with given Difference

#include <bits/stdc++.h>
using namespace std;


//Time: 2^n
int recursive(vector<int> &nums, int diff, int sum, int i){

    if(sum==diff and i==0) return 1;
    if(i<=0) return 0;

    int res =0;
    if(sum+nums[i-1]<=diff) res+= recursive(nums, diff, sum+nums[i-1], i-1);
    res+=recursive(nums, diff, sum, i-1);

    return res;
}

//Time: n*sum => n^2
int recursionWithMemo(vector<int> &nums, vector<vector<int>> &memo, int target, int sum, int i){

    if(sum==target and i==0) return 1;
    if(i==0) return 0;

    if(memo[i-1][sum]!=-1) return memo[i-1][sum];
    memo[i-1][sum] = 0;
    if(sum+nums[i-1]<=target) memo[i-1][sum] += recursionWithMemo(nums, memo, target, sum+nums[i-1], i-1);
    memo[i-1][sum] += recursionWithMemo(nums, memo, target, sum, i-1);

    return memo[i-1][sum];
}


int numberOfSubsetswithDiff(vector<int> &nums, int diff){

    int sum = 0;
    for(auto& i: nums) sum+=i;
    if(sum-diff<0 or (sum-diff)%2) return 0;

    //recursive
    return recursive(nums, (sum-diff)/2, 0, nums.size());

    //recursion with memoization
    // vector<vector<int>> memo(nums.size(), vector<int>(((sum-diff)/2)+1, -1));
    // return recursionWithMemo(nums, memo, (sum-diff)/2, 0, nums.size());

    //tabulation
    // int target = (sum-diff)/2;
    // vector<vector<int>> dp(nums.size(), vector<int> (target+1, 0));

    // //base case
    // if(nums[0]==0) dp[0][0] = 2;
    // else dp[0][0] = 1;
    // if(nums[0]!=0 and nums[0]<=target) dp[0][nums[0]] = 1;

    // for(int i=1;i<nums.size();i++){
    //     for(int j=0;j<=target;j++){
    //         if(nums[i]<=j) dp[i][j] +=dp[i-1][j-nums[i]];
    //         dp[i][j] +=dp[i-1][j];
    //     }
    // }
    // return dp[nums.size()-1][target];

    //tabulation with optimized memory: Space: O(target)
    int target = (sum-diff)/2;
    vector<int> dp(target+1, 0);

    //base case
    if(nums[0]==0) dp[0] = 2;
    else dp[0] = 1;
    if(nums[0]!=0 and nums[0]<=target) dp[nums[0]] = 1;

    for(int i=1;i<nums.size();i++){
        vector<int> tmp(target+1, 0);

        for(int j=0;j<=target;j++){
            if(nums[i]<=j) tmp[j] +=dp[j-nums[i]];
            tmp[j]+=dp[j];
        }
        dp = tmp;
    }
    return dp[target];
}


int main()
{
    vector<int> nums = {5, 2, 6, 4};
    int diff = 3;
    cout<<numberOfSubsetswithDiff(nums, diff)<<endl;

    nums = { 1, 2, 3, 1, 2 };
    diff = 1;
    cout<<numberOfSubsetswithDiff(nums, diff)<<endl;

    nums = {1,0};
    diff = 1;
    cout<<numberOfSubsetswithDiff(nums, diff)<<endl;

    return 0;
}
