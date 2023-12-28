// 930. Binary Subarrays With Sum
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        //hash table + prefix sum
        
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=0;i<n;i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }

        int cnt = 0;
        unordered_map<int, int> mp;
        for(auto& p: prefixSum){
            cnt+=mp[p];
            mp[p+goal]++;
        }
        return cnt;
    }
};

// goal = 2
// [1,0,1,0,1] => nums
// [1,1,2,2,3] => prefixSum
// 0, 3-1, => cnt , map
// 1, 3-2, 
// 0, 4-1, 
// 1, 4-2, 
// 2, 5-1 
// 4 => ans