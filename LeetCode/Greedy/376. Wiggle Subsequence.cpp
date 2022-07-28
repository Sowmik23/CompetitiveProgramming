class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        
        int res = 1;
        if(nums.size()<=1) return 1;
        
        int flag = 0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>0){
                if(flag<=0){
                    res++;
                    flag = 1;
                }
            }
            else if(nums[i]-nums[i-1]<0){
                if(flag>=0){
                    res++;
                    flag = -1;
                }
            }
        }
        
        return res;
    }
};
