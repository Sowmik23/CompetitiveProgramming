class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     
        //use two pointer approach
        
        int sum = 0;
        int left = 0;
        
        int res = INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            while(sum>=target){
                res = min(res, i-left+1);
                sum-=nums[left];
                left++;
            }
        }
        
        if(res==INT_MAX) return 0;
        return res;
    }
};
