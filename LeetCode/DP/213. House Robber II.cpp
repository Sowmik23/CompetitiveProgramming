class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(nums.size()==1) return nums[0];
        
        vector<int> memo(n+1, -1);
        int a = dp(nums, memo, 0, n-1);
        
        memo = vector<int> (n+1, -1);
        int b = dp(nums, memo, 1, n);
        
        return max(a, b);
    }
private:
    int dp(vector<int> &nums, vector<int> &memo, int i, int n){
            
        if(i>=n) return 0;
        
        if(memo[i]!=-1) return memo[i];
        int res = max(dp(nums, memo, i+2, n)+nums[i], dp(nums, memo, i+1, n));
        memo[i] = res;
        
        return res;
    }
};
