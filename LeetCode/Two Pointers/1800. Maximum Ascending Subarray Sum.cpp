class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int maxSum = INT_MIN, sum =0, left =0 , right =0, prev=0;
        while(right<nums.size()){
            if(prev>=nums[right]){
                sum = 0;
                
            }
            prev = nums[right];
            sum+=nums[right];
            maxSum = max(maxSum, sum);
            right++;
        }
        
        return maxSum;
    }
};
