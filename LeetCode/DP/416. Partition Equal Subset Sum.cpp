class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        //Dynamic Programming
        
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum); //calculates array sum
        
        if(sum%2!=0) return false;
        
        return solve(nums, sum/2);
    }
private:
    bool solve(vector<int> &nums, int sum){
        vector<bool> dp(sum+1, false);
        
        dp[0] = true;
        
        for(int i=0;i<nums.size();i++){
            for(int j=sum;j>=nums[i];j--){
                if(j==nums[i] or dp[j-nums[i]]) dp[j] = true;
            }
        }
        
        return dp[sum];
    }
};
