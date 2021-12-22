class Solution {
public:
    int findMin(vector<int>& nums) {
        
        //binary search
        int low = 0, high = nums.size()-1;
        int mid;
        //int res = INT_MAX;
        
        while(low<high){
            mid = low+(high-low)/2;
            if(nums[mid]<nums[nums.size()-1]){
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        
        return nums[low];
    }
};
