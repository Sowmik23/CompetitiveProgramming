class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        //base case: given in test case
        if(k<=0) return 0;
        
        int cnt = 0;
        int left = 0, right = 0;
     
        int mul = 1;
        while(right<nums.size()){
            
            mul*=nums[right];
            
            while(left<=right and mul>=k){
                mul/=nums[left];
                left++;
            }
            
            // (4, 5, 6) =>
            // three subarray (4, (5, (6)))
            cnt+=(right-left+1);  
            
            right++;
        }
        
        return cnt;
    }
};
