// 1493. Longest Subarray of 1's After Deleting One Element
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int left = 0, right = 0;
        int cnt = 0;
        int res = 0;

        while(right<nums.size()){
            if(nums[right]==0) cnt++;
            while(cnt>=2){
                if(nums[left]==0) cnt--;
                left++;
            }
            res = max(res, right-left);
            right++;
        }
        return res;
    }
};