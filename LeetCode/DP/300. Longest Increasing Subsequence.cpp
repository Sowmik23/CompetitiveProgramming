class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
        //recursive:
        //return recursiveLIS(nums, -1, 0);
        
        
        //recursion with memoization
        vector<vector<int>> memo(nums.size()+1, vector<int> (nums.size()+1, -1));
        return recursionWithMemoizationLIS(nums, memo, -1, 0);
        
    }
private:
    int recursiveLIS(vector<int> &nums, int prev, int curr){
        if(curr>=nums.size()) return 0;
        
        int take = 0;
        int notTake = 0;
        if(prev==-1 or nums[prev]<nums[curr]){
            take = 1+recursiveLIS(nums, curr, curr+1);
        }
        notTake = recursiveLIS(nums, prev, curr+1);
        
        return max(take, notTake);
    }
    
    int recursionWithMemoizationLIS(vector<int> &nums, vector<vector<int>> &memo, int prev, int curr){
        if(curr>=nums.size()) return 0;
        
        if(memo[prev+1][curr]!=-1) return memo[prev+1][curr];
        
        int x = 0;
        int y = 0;
        if(prev==-1 or nums[prev]<nums[curr]){
            x = 1+recursionWithMemoizationLIS(nums, memo, curr, curr+1);
        }
        y = recursionWithMemoizationLIS(nums, memo, prev, curr+1);
        
        return memo[prev+1][curr] = max(x, y);
    }
};




class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     
        vector<vector<int>> memo(nums.size()+1, vector<int> (nums.size()+1, -1));
        return dp(nums, memo, 0, -1);
    }
private:
    int dp(vector<int> &nums, vector<vector<int>> &memo, int i, int prev_i){
        if(i>=nums.size()) return 0;
        
        if(memo[i][prev_i+1]!=-1) return memo[i][prev_i+1];
        
        int take = 0;
        
        int dont_take = dp(nums, memo, i+1, prev_i);
        
        if(prev_i==-1 or nums[i]>nums[prev_i]) take = 1+dp(nums, memo, i+1, i);
        
        memo[i][prev_i+1] = max(take, dont_take);
        return memo[i][prev_i+1];
    }
};



