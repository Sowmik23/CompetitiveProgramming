class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     
        //follow up O(n) time
        int i = 1;
        while(i<nums.size()){
            if(nums[i-1]<=nums[i]) i++;
            else break;
        }
        i--;
        
        int j = nums.size()-1;
        while(j-1>i){
            if(nums[j-1]<=nums[j]) j--;
            else break;
        }
    
        int x = nums[i];
        int y = nums[j];
        
        for(int k = i;k<=j;k++){
            if(x>nums[k]) x = nums[k];
            if(y<nums[k]) y = nums[k];
        }
        
        i = 0;
        j = nums.size()-1;
        while(i<j and nums[i]<=x) i++;
        while(j>i and nums[j]>=y) j--;
       
        
        if(i!=j) return j-i+1;
        return j-i;
    }
};
