class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int mini = nums[0];
        int maxi = nums[0];
        
        int ptr = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<mini){
                ptr = i;
                mini = maxi;
            }
            maxi =  max(nums[i], maxi);
        }
        
        return ptr+1;
    }
};
