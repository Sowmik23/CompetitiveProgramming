///Recursive + Memorization
class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        
        memo.assign(nums.size(), -1);
        
        return rob(nums, nums.size()-1);
    }
    
    
private:
    int rob(vector<int> &nums, int n){
        
        if(n<0) return 0;
        if(memo[n]!=-1) return memo[n];
        
        int res =  max(rob(nums, n-2)+nums[n], rob(nums, n-1));
        memo[n] = res;
        return res;
    }    
};
