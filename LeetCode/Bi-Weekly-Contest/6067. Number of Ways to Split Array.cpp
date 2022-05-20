class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        long sum = 0;
        for(auto& i: nums){
            sum+=i;
        }
        
        long x = 0;
        int cnt = 0;
        for(int i=0;i<nums.size()-1;i++){
            x+=nums[i];
            sum-=nums[i];
            
            if(x>=sum) cnt++;
        }
        
        return cnt;
    }
};
