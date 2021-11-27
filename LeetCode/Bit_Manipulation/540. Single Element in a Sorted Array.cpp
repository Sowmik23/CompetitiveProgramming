class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        //Time: O(n)
        //Space: O(1)
        
//         int res = 0;
//         for(int i=0;i<nums.size();i++){
//             res^=nums[i];
//         }
        
//         return res;
        
        
        //Time: O(logn)
        //Space: O(1)
        
        int low = 0, high = nums.size()-2;
        while(low<=high){
            int mid = low+(high-low)/2;
            
            if( (mid%2==0 and nums[mid]==nums[mid+1]) or (mid%2==1 and nums[mid]==nums[mid-1])){
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return nums[low];
    }
};
