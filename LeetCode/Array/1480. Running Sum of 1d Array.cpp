class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        /*int sum = 0;
        vector<int> nums1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            nums1.push_back(sum);
        }
        return nums1;
        */

        /*int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            nums[i] = sum;
        }
        return nums;*/
        
        for(int i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }
};
