// 1838. Frequency of the Most Frequent Element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        

        //sliding window
        sort(nums.begin(), nums.end());
        int res = 0;
        long curr = 0;

        int left = 0, right = 0;
        while(right<nums.size()){
            long target = nums[right];
            curr+=target;
            while((right-left+1)*target - curr > k){
                curr -= nums[left];
                left++;
            }
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};