class Solution {
public:
    bool canJump(vector<int>& nums) {
     
        //if(nums.size()==1) return true;
        
        
        //Approach-01: dp-recursion/brute force: TLE
        /*vector<bool> dp(nums.size()+1, false);
        
        dp[0] = true;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==true){
                for(int j=i+1;j<=i+nums[i] and j<nums.size();j++){
                    dp[j] = true;   
                }
            }
        }
        
        return dp[nums.size()-1];*/
        
        
        vector<bool> dp(nums.size()+1, false);
        
        int mx = 0;
        dp[0] = true;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==true or i<=mx){
                if(i+nums[i]>=nums.size()-1) return true;
                else {
                    mx = max(mx, i+nums[i]);
                }
            }
        }
        
        return false;
    }
};
