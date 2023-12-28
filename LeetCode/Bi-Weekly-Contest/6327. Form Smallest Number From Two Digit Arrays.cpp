// 6327. Form Smallest Number From Two Digit Arrays

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        
        
        unordered_map<int, int> mp, mp2;
        for(auto& n: nums1) mp[n]++;
        for(auto& n: nums2) mp2[n]++;
        
        for(int i=1;i<=9;i++){
            if(mp.find(i)!=mp.end() and mp2.find(i)!=mp2.end()) return i;
        }
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int x = nums1[0];
        int y = nums2[0];
        int res;
        
        if(x<y) res = x*10+y;
        else res = y*10+x;
        return res;
    }
};