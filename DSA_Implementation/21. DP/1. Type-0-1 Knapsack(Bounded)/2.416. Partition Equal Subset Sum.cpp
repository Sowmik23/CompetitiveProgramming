// Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same.
// 416. Partition Equal Subset Sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for(auto& n: nums){
            sum+=n;
        }
        if(sum%2) return false;
        int target = sum/2;

        //recursive solution: TLE
        return recursive(nums, target, nums.size());

        //recursion with memoization: Accepted
        vector<vector<int>> memo(nums.size()+1, vector<int> (target+1, -1));
        return recursionWithMemoization(nums, memo, target, nums.size());

        //tabulation: Accepted
        vector<vector<int>> dp(nums.size()+1, vector<int> (target+1));
        //initialize with base case
        for(int i=0;i<=target;i++){
            dp[0][i] = 0;
        }
        for(int i=0;i<=nums.size();i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j) dp[i][j] = (dp[i-1][j-nums[i-1]] or dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[nums.size()][target];

        //tabulation
        int target = (sum-diff)/2;
        vector<vector<int>> dp(nums.size(), vector<int> (target+1, 0));
        //base case
        for(int i=0;i<=target;i++) dp[0][i] = 0;
        for(int i=0;i<nums.size();i++) dp[i][0] = 1;

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<=target;j++){
                if(nums[i]<=j) dp[i][j] +=dp[i][j-nums[i]];
            }
        }
        return dp[nums.size()-1][target];
    }
private:
    bool recursive(vector<int> &nums, int target, int i){
        if(target==0) return true;
        if(i==0) return false;
        if(nums[i-1]>target) recursive(nums, target, i-1);
        return (recursive(nums, target-nums[i-1], i-1) or recursive(nums, target, i-1));
    }

    bool recursionWithMemoization(vector<int> &nums, vector<vector<int>> &memo, int target, int i){
        if(target==0) return true;
        if(i==0) return false;
        if(memo[i-1][target]!=-1) return memo[i-1][target];

        if(nums[i-1]>target) return memo[i-1][target] = recursionWithMemoization(nums, memo, target, i-1);
         return memo[i-1][target]  = (recursionWithMemoization(nums, memo, target-nums[i-1], i-1) or recursionWithMemoization(nums, memo, target, i-1));
    }
};
