class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        sort(nums.begin(), nums.end());
        
        for(auto& n: nums){
            freq[n]++;
        }
        
        vector<int> memo(nums.size()+2, -1);    
        return dp(nums, freq, memo,  0);
    }
private:
    int dp(vector<int> &nums, unordered_map<int, int> &freq, vector<int> &memo, int i){
        
        if(i>=nums.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        
        int currIdx = i;
        int currValue = nums[i];
        int nextIdx;
        
        while(currIdx<nums.size() and nums[currIdx]==currValue) currIdx++;
        nextIdx = currIdx;
        
        while(nextIdx<nums.size() and nums[nextIdx]==currValue+1) nextIdx++;
        
        return memo[i] = max(dp(nums, freq, memo, nextIdx)+(freq[currValue]*currValue), dp(nums, freq, memo, currIdx));
    }
};
