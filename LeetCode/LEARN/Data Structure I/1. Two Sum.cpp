class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> mp;
        
        for(int i=0;i<nums.size();i++){
            int b = target - nums[i];
            
            if(mp.find(b)!=mp.end() and mp[b]!=i) return {i, mp[b]};
            else {
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};
