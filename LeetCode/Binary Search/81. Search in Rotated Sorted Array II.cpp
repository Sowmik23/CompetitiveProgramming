class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        //Time: O(n)
        /*
        int midIndex = 0; 
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]) {
                midIndex = i;
                break;
            }
        }
       
        bool out1 = binarySearch(nums, target, 0, midIndex);
        if(out1==true) return true;
        bool out2 = binarySearch(nums, target, midIndex, nums.size());
        return out2;
        */
        
        
        //Time: O(logn)
        
        int left = 0, right = nums.size()-1;
        int mid;
        
        while(left<=right){
            
            while(left<right and nums[left]==nums[left+1]) left++;
            while(left<right and nums[right]==nums[right-1]) right--;
            
            mid = left+(right-left)/2;
            if(nums[mid]==target) return true;
            
            
            if(nums[mid]>=nums[left]){
                //target is in left part
                if( target>=nums[left] and target<nums[mid]) right = mid-1;
                else left = mid+1;
            }
            else {
                //target exists in left part
                if(target<=nums[right] and target>nums[mid]){
                    left = mid+1;
                }
                else right = mid-1; 
            }
        }
        
        return false;
    }
private:
    bool binarySearch(vector<int> &nums, int target, int left, int right){
        if(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target) return true;
            
            if(nums[mid]>target) return binarySearch(nums, target, left, mid);
            else return binarySearch(nums, target, mid+1, right);
        }
        
        return false;
    }
};
