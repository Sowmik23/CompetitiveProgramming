// 740. Delete and Earn
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(auto& num: nums){
            mp[num]++;
        }

        sort(nums.begin(), nums.end());

        //recursion: TLE
        // int res = dp(0, nums, mp);
        // return res;

        //recursion with memoization
        vector<int> memo(nums.size(), -1);
        int res = recursionWithMemo(0, nums, mp, memo);
        return res;
    }
private:
    int dp(int index, vector<int> &nums, unordered_map<int, int> &mp){
       
       if(index>=nums.size()) return 0;
       int currIdx = index;
       int currVal = nums[currIdx];
       while(currIdx<nums.size() and nums[currIdx]==currVal) currIdx++;
       int nextIdx = currIdx;

       while(nextIdx<nums.size() and nums[nextIdx]==currVal+1) nextIdx++;

       return max(mp[currVal]*currVal+dp(nextIdx, nums, mp), dp(currIdx, nums, mp));
    }
    int recursionWithMemo(int index, vector<int> &nums, unordered_map<int, int> &mp, vector<int> &memo){
        if(index>=nums.size()) return 0;
        if(memo[index]!=-1) return memo[index];

        int currIndex = index;
        int currVal = nums[index];
        while(currIndex<nums.size() and nums[currIndex]==currVal) currIndex++;
        int nextIndex = currIndex;

        while(nextIndex<nums.size() and nums[nextIndex]==currVal+1) nextIndex++;
        return memo[index] = max(mp[currVal]*currVal+recursionWithMemo(nextIndex, nums, mp, memo), recursionWithMemo(currIndex, nums, mp, memo));
    }
};