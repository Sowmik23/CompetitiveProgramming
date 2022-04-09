class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     
        int i = nums.size()-2;
        
        while(i>=0 and nums[i]>=nums[i+1]){
            i--;
        }
        
        int n = nums.size();
        if(i<0) return sort(nums.begin(), nums.end());
        else {
            int index = binarySearch(nums, i+1, n-1, nums[i]);
            swap(nums[i], nums[index]);
            
            reverseArray(nums, i+1, n-1);    
        }
    }
private:
    int binarySearch(vector<int> &nums, int low, int high, int val){
        
        int index = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]<=val) high = mid-1;
            else {
                low = mid+1;
                if(index==-1 or nums[index]>=nums[mid]) index = mid;
            }
        }
        return index;
    }
    
    void reverseArray(vector<int> &nums, int l, int r){
        while(l<r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};
