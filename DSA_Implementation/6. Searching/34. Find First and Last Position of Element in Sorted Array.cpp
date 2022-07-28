class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     
        
        int lowerBound = -1;
        int upperBound = -1;
        
        if(nums.size()<1) return {lowerBound, upperBound};
        
        lowerBound = lowerbound(nums, target);
        upperBound = upperbound(nums, target);
        
        if(lowerBound <nums.size() and nums[lowerBound]!=target) lowerBound = -1;
        if(upperBound>=0 and nums[upperBound]!=target) upperBound = -1;
        
        return {lowerBound, upperBound};
    }
private:
    int lowerbound(vector<int> &nums, int target){
        int left = 0, right = nums.size()-1;
        
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>=target) right = mid;
            else left = mid+1;
        }
        
        if(left>=0 and nums[left]!=target) left--;
        return left;
    }
    int upperbound(vector<int> &nums, int target){
        
        int left = 0, right = nums.size()-1;
        
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>target) right = mid;
            else left = mid + 1;
        }
        if(left<nums.size() and nums[left]!=target) left--;
        return left;
    }
};
