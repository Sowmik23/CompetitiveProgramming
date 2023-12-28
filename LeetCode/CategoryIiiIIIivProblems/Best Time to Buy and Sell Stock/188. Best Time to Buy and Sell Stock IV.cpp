class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n/2) {
            // fast case because there are [0, n/2] continuous increases
            int maxProfit = 0;
            for (int i = 1; i < n; i++) {
                int diff = prices[i] - prices[i-1];
                if (diff > 0) {
                    maxProfit += diff;
                }
            }
            return maxProfit;
        }

        // Each element dp[i][j] means the max profit of at most i transactions until day j
        vector<vector<int>> dp(k+1, vector<int> (n));
        int localMax = INT_MIN;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j < n; j++) {
                localMax = max(localMax, dp[i-1][j-1] - prices[j-1]);
                dp[i][j] = max(dp[i][j-1], localMax + prices[j]);
            }
            localMax = INT_MIN;
        }
        return dp[k][n-1];
    }
};
