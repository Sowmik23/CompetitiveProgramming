class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        
        //nice problem: also try 4/5 subsequences
        
        int a = INT_MAX;
        int b = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(a>=nums[i]){
                a = nums[i];
            }
            else if(b>=nums[i]){
                b = nums[i];
            }
            else return true;
        }
        
        return false;
    }
};
