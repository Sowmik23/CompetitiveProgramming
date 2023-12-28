// 2537. Count the Number of Good Subarrays
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        long long cnt = 0;

        while(right<n){
            k-=mp[nums[right]];
            mp[nums[right]]++;
            right++;
            while(k<=0){
                mp[nums[left]]--;
                k+=mp[nums[left]];
                left++;
            }
            cnt+=left;
            
        }
        return cnt;
    }
};