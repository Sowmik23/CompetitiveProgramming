class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        
        ///Approach: 01: Using sliding window: Wrong approach as values can be negative
        
//         int left = 0, right = 0;
//         int leftRepresentative = -1; //left agent
//         int cnt = 0;
//         int sum = 0;
        
//         while(right<nums.size()){
//             sum+=nums[right];
            
//             while(sum>k){
//                 sum-=nums[left];
//                 left++;
//             }
//             if(sum==k){
//                // cout<<left<<" "<<right<<endl;
//                 if(leftRepresentative-left<=0) cnt++;
//                 leftRepresentative = right;
//             }
//             right++;
//         }
        
//         return cnt;
        
        
        ///Approach-02: Hash Map
        unordered_map<int, int> mp;
        
        mp[0]++;
        
        int res = 0;
        int sum = 0;
        for(auto& i: nums){
            sum+=i;
            
            if(mp.count(sum-k)) res+=mp[sum-k];
            mp[sum]++;
        }
        
        return res;
    }
};
