class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int mx = 0;
        
    
        int cnt = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) cnt++;
            else {
                mx = max(mx, cnt);
                cnt = 0;
            }
        }
        mx = max(mx, cnt);
        
        return mx;
    }
};
