// 2444. Count Subarrays With Fixed Bounds
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        //Time: O(n)
        //Space: O(1)
        int leftBound = -1;
        int minPosition = -1;
        int maxPosition = -1;

        long long res = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==minK) minPosition = i;
            if(nums[i]==maxK) maxPosition = i;
            if(nums[i]<minK or nums[i]>maxK) leftBound = i;

            res+= max(0, min(minPosition, maxPosition)-leftBound);
        }
        return res;
    }
};