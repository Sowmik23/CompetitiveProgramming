class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        ///Approach: 01 sorting: Time: nlogn, Space: O(1)
       /* sort(nums.begin(), nums.end());
        int mx = 1, cnt = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                cnt++;
                if(cnt>mx) mx = cnt;
            }
            else {
                cnt = 1;
            }
        }
        if(mx>=2) return true;
        return false;
        
        */
        
        ///Approach: 02 : unordered_map: Time: O(n)
        unordered_map<int, int> mp;
        
        for(auto i: nums){
            mp[i]++;
        }
        
        for(auto i: mp){
            if(i.second>=2) return true;
        }
        return false;
    }
};
