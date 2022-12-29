class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {

        unordered_map<int, int> mp;

        for(auto& n: nums){
            mp[n%space]++;
        }

        int mxFreq = INT_MIN;
        for(auto& f: mp){
            mxFreq = max(mxFreq, f.second);
        }

        int minRes = INT_MAX;
        for(int i=0;i<nums.size();i++){
           if(mp[nums[i]%space]==mxFreq) minRes = min(minRes, nums[i]);
        }

        return minRes;
    }
};
