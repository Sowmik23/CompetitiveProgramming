class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        if(nums.size()<3) return false;
        
        stack<int> stk;
        int s3 = INT_MIN;
        
        for(int i=nums.size()-1;i>=0;i--){
            
            if(s3>nums[i]) return true;
            else {
                while(!stk.empty() and nums[i]>stk.top()){
                    s3 = stk.top();
                    stk.pop();
                }
                stk.push(nums[i]);
            }
        }
        
        return false;
    }
};
