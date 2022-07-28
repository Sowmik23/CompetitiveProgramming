class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int res = 0;
        int prevMn = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<prevMn){
                res++;
                if(res==2) return false; //that means if we modify 2 elements
                if(i-2>=0 and nums[i-2]>nums[i]) continue;
            } 
            prevMn = nums[i];
        }
        
        return true;   
    }
};
