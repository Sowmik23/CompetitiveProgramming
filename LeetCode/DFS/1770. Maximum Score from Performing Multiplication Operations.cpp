class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {

        //recursive: TLE
        //return recursive(nums, multipliers,  0, nums.size()-1,0);

        //recursion with memoization
        //Memory limit exceeded
        vector<vector<int>> memo(multipliers.size(), vector<int> (multipliers.size(), INT_MIN));
        return recursionWithMemoization(nums, multipliers, memo, 0, 0);

        //return dfs(nums, multipliers, 0, 0);
    }
private:
    int recursive(vector<int> &nums, vector<int> &multipliers, int start, int end, int i){
        // if(start>=nums.size()) return 0;
        // if(end<0) return 0;
        if(i>=multipliers.size()) return 0;

        int x = recursive(nums, multipliers, start+1, end, i+1)+(nums[start]*multipliers[i]);
        int y = recursive(nums, multipliers, start, end-1, i+1)+(nums[end]*multipliers[i]);
        return max(x, y);
    }

    int recursionWithMemoization(vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &memo, int start, int i){

        if(i>=multipliers.size()) return 0;
        if(memo[start][i]!=INT_MIN) return memo[start][i];

        int end = nums.size()-1 - (i-start);

        memo[start][i] = max(recursionWithMemoization(nums, multipliers, memo, start+1, i+1)+nums[start]*multipliers[i], recursionWithMemoization(nums, multipliers, memo, start, i+1)+nums[end]*multipliers[i]);

        return memo[start][i];
    }

    int dp[1001][1001] = {};
    int dfs(vector<int>& nums, vector<int>& multipliers, int l, int i) {
        if (i >= multipliers.size())
            return 0;
        if (!dp[l][i]) {
            int r = nums.size() - 1 - (i - l);
            dp[l][i] = max(nums[l] * multipliers[i] + dfs(nums, multipliers, l + 1, i + 1),
                nums[r] * multipliers[i] + dfs(nums, multipliers, l, i + 1));
        }
        return dp[l][i];
    }
};
