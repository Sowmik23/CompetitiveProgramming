// 1248. Count Number of Nice Subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int cnt = 0;
        int res = 0;
        int left = 0, right = 0;

        while(right<nums.size()){
            if(nums[right]%2) {
                k--;
                cnt = 0;
            }
            while(k==0){
                k+=(nums[left]%2==1 ? 1 : 0);
                left++;
                cnt++;
            }
            res+=cnt;
            right++;
        }
        return res;
    }
};
