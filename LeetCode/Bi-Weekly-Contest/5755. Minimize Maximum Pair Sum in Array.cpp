class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int res = 0;
        int j=nums.size()-1;
        
        for(int i=0;i<nums.size()/2;i++){
            res = max(res, nums[i]+nums[j]);
            j--;
        }
        
        return res;
    }
};
