class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        
        int left = 0, right = nums.size(), mid;
        
        while(left<right){
            mid = (left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target){
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        // if(left<right and nums[left]<=target){
        //     left++;
        // }
        
        return left;
    }
};
