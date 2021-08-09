class Solution {
public:
    int maximumProduct(vector<int>& nums) {
     
        ///Approach:01 Sorting: Very much technical question 
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        return max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
    }
};
