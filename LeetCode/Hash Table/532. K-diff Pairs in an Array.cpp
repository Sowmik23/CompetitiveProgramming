class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        
        //Sol^n: just find out if nums[i]+k is present in the map or not
        // - if k<0 then ans is 0. as absolute difference can not be negative.
        
        // Approach-01: unordered_map
        // Time: O(n)
        // Space: O(n)
        
//         unordered_map<int, int> mp;
        
//         for(auto& i : nums) mp[i]++;
        
//         int res = 0;
//         for(auto& i : mp){
//             if((k==0 and i.second>1) or (k!=0 and mp.find(i.first+k)!=mp.end())) res++;
//         }
        
//         return res;
        
        // Approach-02: two pointer
        // Time: O(nlogn)
        // Space: O(1)
        
        sort(nums.begin(), nums.end());
        
        int left = 0, right = 1, res = 0;
        while(left<nums.size() and right<nums.size()){
            if(nums[left]+k<nums[right]) left++;
            else if(left==right or nums[left]+k>nums[right]) right++;
            else {
                res++;
                left++;
                
                while(left<nums.size() and nums[left]==nums[left-1]){
                    left++;
                }
                right = max(left+1, right+1);
            }
        }
        
        return res;
    }
};
