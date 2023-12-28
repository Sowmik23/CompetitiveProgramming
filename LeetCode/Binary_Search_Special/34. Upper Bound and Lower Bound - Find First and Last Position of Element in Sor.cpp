// 34. Find First and Last Position of Element in Sorted Array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        //binary search

        int n = nums.size();
        if(n==0) return {-1, -1};

        // int lowerBound = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // int upperBound = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        int lowerBound = getLowerBound(nums, target);
        int upperBound = getUpperBound(nums, target);

        cout<<lowerBound<<" "<<upperBound<<endl;
        
        upperBound--;
        if((lowerBound<n and nums[lowerBound]!=target) or lowerBound>=n) lowerBound = -1;
        if(upperBound>=0 and nums[upperBound]!=target) upperBound = -1;

        return {lowerBound, upperBound};
    }
private:
    int getLowerBound(vector<int> &nums, int target){
        int left = 0, right = nums.size()-1;
        int mid;
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid]>=target) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
    int getUpperBound(vector<int> &nums, int target){
        int left = 0, right = nums.size()-1;
        int mid;
        while(left<=right){
            mid = left + (right-left)/2;
            if(nums[mid]>target) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};