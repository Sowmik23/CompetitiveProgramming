class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        //approach: hash table Time: O(n) Space: O(n)
        unordered_map<int, int> mp;
        
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(mp[k-nums[i]]>0){
                cnt++;
                mp[k-nums[i]]--;
            } 
            else mp[nums[i]]++;
        }
        
        return cnt;
        
        //approach-02: sorting + two pointer : Time: O(nlogn), Space: O(1) 
    /*
        sort(nums.begin(), nums.end());
        
        int cnt = 0;
        int i = 0, j = nums.size()-1;
        while(i<j){
            while(i<j and (long)nums[i]+nums[j]==k){
                cnt++;
                i++;
                j--;
            }
            if((long)nums[i]+nums[j]>k) j--;
            else i++;
        }
        
        
        return cnt;
    */
    }
};
