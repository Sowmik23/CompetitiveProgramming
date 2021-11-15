class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> res(nums.size(), 1);
        
        for(int i=1;i<nums.size();i++){
            res[i]*=(res[i-1]*nums[i-1]);
        }
        for(int i=nums.size()-2;i>=0;i--){
            res[i] *= nums[i+1];
            nums[i] *=nums[i+1];
        }
        
        return res;
    }
};
