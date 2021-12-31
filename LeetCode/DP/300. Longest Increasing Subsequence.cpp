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
