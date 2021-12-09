class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        if(nums.size()==1) return nums[0];
        
        int mx = 0;
        int posMax = 0;
        int negMax = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) swap(posMax, negMax);
            
            posMax = max(posMax*nums[i], nums[i]);
            negMax = min(negMax*nums[i], nums[i]);
            
            mx = max(mx, posMax);
        }
        
        return mx;
    }
};
