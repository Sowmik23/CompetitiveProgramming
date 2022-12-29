class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        int i = 0;
        int n = nums.size();
        while(i<n){
            if(i<=k){
                if(mp.find(nums[i])!=mp.end()) return true;
                mp[nums[i]] = 1;
            }
            else {
                mp.erase(nums[i-k-1]);
                if(mp.find(nums[i])!=mp.end()) return true;
                mp[nums[i]] = 1;
            }
            i++;
        }
        return false;
    }
};
