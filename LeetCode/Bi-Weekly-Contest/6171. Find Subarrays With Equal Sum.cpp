class Solution {
public:
    bool findSubarrays(vector<int>& nums) {

        if(nums.size()<=2) return false;

//         unordered_map<int, int> mp;
//         for(auto& n: nums){
//             mp[n]++;
//         }

//         bool flag = false;
//         bool res = false;
//         for(auto& m: mp){
//             if(m.second>=2){
//                 if(m.second>2) flag = true;
//                 res = true;
//             }
//         }
        unordered_map<long, bool> mp;
        long sum ;
        for(int i=1;i<nums.size();i++){
            sum = nums[i-1] + nums[i];
            if(mp.find(sum)!=mp.end()) return true;
            mp[sum]  = true;
        }

        return false;
    }
};
