// 1685. Sum of Absolute Differences in a Sorted Array

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        

        //prefix sum
        //time: O(n)
        //Space: O(n)

        int n = nums.size();
        vector<int> res;
        vector<int> prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        for(int i=0;i<n;i++){
            int leftSum = prefixSum[i]-nums[i];
            int rightSum = prefixSum[n-1] - prefixSum[i];

            int leftCnt = i;
            int rightCnt = n-i-1;

            int total = ((leftCnt*nums[i]) - leftSum) + (rightSum - (rightCnt*nums[i]));
            res.push_back(total);
        }   
        return res;
    }
};