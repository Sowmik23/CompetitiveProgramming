class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        
        ///Simple: Apply Kadane's Algorithm but also try to find the range and print it;
        
        int maxSum = INT_MIN;
        int partialSum = 0;
        
        for(auto& num: nums){
            partialSum +=num;
            
            if(partialSum>maxSum) maxSum = partialSum;
            
            if(partialSum<0) partialSum = 0;
        }
        
        return maxSum;
    }
};
