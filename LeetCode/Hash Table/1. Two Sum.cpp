class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res(2);
        unordered_map<int, int> mp;
        
        for(int i=0;i<nums.size();i++){
            int x = target - nums[i];
            
            if(mp.find(x)!=mp.end()){
                // res[0] = i;
                // res[1] = mp[x];
                // break;
                
                return {mp[x], i};
            }
            else {
                mp[nums[i]] = i;
            }
        }
        
        return res;
    }
};
