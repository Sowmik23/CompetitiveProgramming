class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {


        int nonCircularMaxSum = kadanesAlgo(nums);

        int totalSum = 0;
        for(int i=0;i<nums.size();i++) {
            totalSum+=nums[i];
            nums[i] = -nums[i];
        }
        int circularSum = totalSum + kadanesAlgo(nums);  //it's find min sum;
        if(circularSum==0) return nonCircularMaxSum;
        return max(circularSum, nonCircularMaxSum);
    }
private:
    int kadanesAlgo(vector<int> &nums){
        //kadane's algorithm
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxSum) maxSum = sum;
            if(sum<0) sum = 0;
        }
        return maxSum;
    }
};
