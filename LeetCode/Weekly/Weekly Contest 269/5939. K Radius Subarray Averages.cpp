class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        if(k==0) return nums;
        vector<int> res(nums.size(), -1);
        
        long long sum = 0;
        
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(i>=2*k){
                int pos = (i+(i-2*k))/2;
                res[pos] = (sum/(2*k+1));
                
                sum-=nums[i-(2*k)];
            }
            
        }
        
        
        return res;
    }
};
