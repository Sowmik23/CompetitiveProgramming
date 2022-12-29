class Solution {
public:
    int rob(vector<int>& nums) {

        // Recursive
        //return recursive(nums, nums.size());

        // Recursion with memoization
        // vector<int> memo(nums.size(), -1);
        // return recursionWithMemo(nums, memo, nums.size());

        // Tabulation
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;
        for(int i=1;i<=nums.size();i++){
            if(i>1) dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
            else dp[i] = max(dp[i-1]+nums[i-1], dp[i]);
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
        if(memo[i-1]!=-1) return memo[i-1];
        memo[i-1] = max(recursionWithMemo(nums, memo, i-2)+nums[i-1], recursionWithMemo(nums, memo, i-1));
        return memo[i-1];
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int> memo(nums.size()+2, -1);

        return dp(0, nums, memo);
    }

private:
    int dp(int i, vector<int> &nums, vector<int> &memo){

        if(i>=nums.size()) return 0;
        if(memo[i]!=-1) return memo[i];

        //first ta nilam then i+2 er ta neoar jonno call dilam
        //or first ta nilam na. just por er ta te move korlam
        int res = max(dp(i+2, nums, memo)+nums[i], dp(i+1, nums, memo));
        memo[i] = res;
        return res;
    }
};
