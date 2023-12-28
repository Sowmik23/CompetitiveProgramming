class Solution {
public:
    int rob(vector<int>& nums) {

        //recursive:
        // return recursive(nums, nums.size());

        // vector<int> memo(nums.size()+1, -1);
        // return recursionWithMemo(nums, memo, nums.size());

        //tabulation
        vector<int> dp(nums.size()+1, 0);
        dp[0]=0;
        for(int i=1;i<=nums.size();i++){
            if(i>1) dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
            else dp[i]=max(dp[i-1]+nums[i-1], dp[i]);
        }
        return dp[nums.size()];
    }
private:
    int recursive(vector<int> &nums, int i){
        if(i<=0) return 0;

        return max(recursive(nums, i-2)+nums[i-1], recursive(nums, i-1));
    }
    int recursionWithMemo(vector<int> &nums, vector<int> &memo, int i){
        if(i<=0) return 0;
        if(memo[i]!=-1) return memo[i];
        return memo[i] = max(recursionWithMemo(nums, memo, i-2)+nums[i-1], recursionWithMemo(nums, memo, i-1));
    }
};
