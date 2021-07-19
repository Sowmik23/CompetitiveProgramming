class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int left =0, right = 0;
        int res = 0;
        int numofConversion = 0;
        
        while(right<nums.size()){
            if(nums[right]==0){
                numofConversion++;
            }
            while(numofConversion > k){
                if(nums[left]==0){
                    numofConversion--;
                }
                left++;
            }
            
            res = max(res, right-left+1);
            
            right++;
        }
        
        return res;
    }
};
