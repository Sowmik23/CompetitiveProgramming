class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        
        //Approach-01: Time: nlogn, Space: O(1)
        /*
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> res;
        int i = 0, j= 0;
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]>nums2[j]) j++;
            else {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return res;
        */
        
        //Approach-02: Time: O(n), Space: O(n)
        
        unordered_map<int, int> mp;
        
        if(nums1.size()>nums2.size()){
            intersect(nums2, nums1);
        }
        
        //now we are sure that nums1's size is always <=nums2
        for(auto& num: nums1){
            mp[num]++;
        }
        
        vector<int> res;
        for(auto& num: nums2){
            if(mp[num]>=1){
                res.push_back(num);
                mp[num]--;
            }
        }
        
        return res;
    }
};
