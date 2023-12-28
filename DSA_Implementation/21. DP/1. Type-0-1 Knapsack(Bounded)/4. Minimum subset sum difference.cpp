#include <bits/stdc++.h>
using namespace std;

int res = 0;
int recursive(vector<int> &nums, int sum, int target, int total, int i){
	if(target==0) {
	    if(abs(sum-total)<abs(sum-res)) res = total;
	    return 0;
	}
	if(i==0) {
	    if(abs(sum-total)<abs(sum-res)) res = total;
	    return 0;
	}

	if(nums[i-1]<=target) recursive(nums, sum, target-nums[i-1], total+nums[i-1], i-1);
	recursive(nums, sum, target, total, i-1);
	return res;
}

//oh recursion! I love you but you always neglects me :(
int modifiedRecursive(vector<int> &nums, int totalSum, int calculatedSum, int i){
    if(i==0) return abs((totalSum-calculatedSum)-calculatedSum); //calculatedSum is one sub-arrays sum and (totalSum-calculatedSum) is another sub-arrays sum. and here we calculate the minimum diff always

    return min(modifiedRecursive(nums, totalSum, calculatedSum+nums[i-1], i-1), modifiedRecursive(nums, totalSum, calculatedSum, i-1));
}

int modifiedRecursionWithMemo(vector<int> &nums, vector<vector<int>> &memo, int totalSum, int calculatedSum, int i){
    if(i==0){
        return abs((totalSum-calculatedSum)-calculatedSum);
    }
    if(memo[i-1][calculatedSum]!=-1) return memo[i-1][calculatedSum];

    memo[i-1][calculatedSum] = min(modifiedRecursionWithMemo(nums, memo, totalSum, calculatedSum+nums[i-1], i-1),
    modifiedRecursionWithMemo(nums, memo, totalSum, calculatedSum, i-1));

    return memo[i-1][calculatedSum];
}

int minSumDiff(vector<int> &nums){

	int sum = 0;
	for(auto& i: nums) sum+=i;

// 	int sm = recursive(nums, sum/2, sum/2, 0, nums.size());
// 	int x = sum-sm;
// 	return abs(sm-x);


    //recursive
    //return modifiedRecursive(nums, sum, 0, nums.size());

    //recursion with memoization
    // vector<vector<int>> memo(nums.size(), vector<int> (sum+1, -1));
    // return modifiedRecursionWithMemo(nums, memo, sum, 0, nums.size());


    //tabulation
    vector<vector<int>> dp(nums.size()+1, vector<int> (sum+1));
    for(int i=0;i<=nums.size();i++) dp[i][0] = 1;
    for(int i=1;i<=sum;i++) dp[0][i] = 0;

    for(int i=1;i<=nums.size();i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(nums[i-1]<=j) dp[i][j] |= dp[i-1][j-nums[i-1]];
        }
    }

    int mn = INT_MAX;
    for(int i=sum/2;i>=0;i++){
        if(dp[nums.size()][i]==true) {
            mn = sum-2*i;
            break;
        }
    }
    return mn;


    // tabulation with optimized memory
    // TODO:
}

int main(){
	vector<int> nums = {1, 3, 5, 14};
	cout<<minSumDiff(nums)<<endl; //ans = 5

	nums = {1, 6, 11, 5} ;
	cout<<minSumDiff(nums)<<endl; //ans = 1

    nums = { 3, 1, 4, 2, 2, 1 };
    cout<<minSumDiff(nums)<<endl; //ans = 1

    nums = { 3, 4, 5, 6 };
    cout<<minSumDiff(nums)<<endl; //ans = 0

    nums = { 3,9,7,3};
    cout<<minSumDiff(nums)<<endl; //ans = 2

    nums = { -36, 36 };
    cout<<minSumDiff(nums)<<endl; //ans = 72

    nums = { 5, 3, 10, 6 };
    cout<<minSumDiff(nums)<<endl; //ans = 2

	return 0;
}
