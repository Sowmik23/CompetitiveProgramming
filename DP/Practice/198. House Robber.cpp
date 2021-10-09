class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> memo(nums.size()+2, -1);
        
        return dp(0, nums, memo);
    }
    
private:
    int dp(int i, vector<int> &nums, vector<int> &memo){
        
        if(i>=nums.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        
        //first ta nilam then i+2 er ta neoar jonno call dilam
        //or first ta nilam na. just por er ta te move korlam 
        int res = max(dp(i+2, nums, memo)+nums[i], dp(i+1, nums, memo)); 
        memo[i] = res;
        return res;
    }
};
