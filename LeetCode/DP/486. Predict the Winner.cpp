 // 486. Predict the Winner
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        //Dynamic Programming
        //Maximizing the difference of score between player 1 and 2

        int n = nums.size();

        //recursive: O(2^n)
        // return recursive(nums, 0, n-1)>=0;

        //recursion with memoization: O(n^2)
        // vector<vector<int>> memo(n, vector<int> (n, -1));
        // return recursionWithMemo(nums, 0, nums.size()-1, memo)>=0;

        //tablulation: O(n^2)
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0;i<n;i++) dp[i][i] = nums[i];

        for(int k=1;k<n;k++){
            for(int i=0;i<n-k;i++){
                int j = i+k;
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]); 
            }
        }
        return dp[0][n-1]>=0;
    }
private:
    int recursive(vector<int> &nums, int i, int j){
        if(i==j) return nums[i];

        int takeLeft = nums[i] - recursive(nums, i+1, j);
        int takeRight = nums[j] - recursive(nums, i, j-1);

        return max(takeLeft, takeRight);
    }

    int recursionWithMemo(vector<int> &nums, int i, int j, vector<vector<int>> &memo){
        if(i==j) return nums[i];
        if(memo[i][j]!=-1) return memo[i][j];

        int left = nums[i] - recursionWithMemo(nums, i+1, j, memo);
        int right = nums[j] - recursionWithMemo(nums, i, j-1, memo);
        return memo[i][j] = max(left, right);
    }
};