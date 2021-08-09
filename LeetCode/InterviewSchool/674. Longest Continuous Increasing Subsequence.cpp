class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int maxCnt = 1;
        int cnt = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) cnt++;
            else {
                maxCnt = max(maxCnt, cnt);
                cnt = 1;
            }
        }
        maxCnt = max(maxCnt, cnt);
        
        return maxCnt;
    }
};
