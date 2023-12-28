// 2295. Replace Elements in an Array
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++) mp[nums[i]] = i;
        
        for(auto& operation: operations){
            int pos = mp[operation[0]];
            nums[pos] = operation[1];
            mp[operation[1]] = pos;
        }
        return nums;
    }
};
