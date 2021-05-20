

//#Remove duplicates from a sorted array
//Two Pointer: O(n) +  O(1) 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        int j = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        
        return j+1;
    }
};
