class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        
        ///Simple: Just use kadane's algorithm : Time: O(n), Space: O(1)
        int sum = 0;
        int maxSum = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(maxSum<sum) maxSum = sum;
            if(sum<0) sum = 0;
        }
        return maxSum;
    }
};
