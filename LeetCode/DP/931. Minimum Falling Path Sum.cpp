class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        int result = INT_MAX;

        vector<vector<int>> dp(m+1, vector<int> (n+1, INT_MAX));

        for(int i = 0; i < n; i++){
            result = min(result, solve(m - 1, i, matrix, dp));
        }


        return result;
    }
private:
    int solve(int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp){

        if(n < 0 || n >= matrix[m].size()) return INT_MAX;

        if(m == 0) return matrix[0][n];
        if(dp[m][n]!=INT_MAX) return dp[m][n];

        int up = solve(m - 1, n, matrix, dp);
        int left = solve(m - 1, n - 1, matrix, dp);
        int right = solve(m - 1, n + 1, matrix, dp);

        return dp[m][n] = min(min(left, right), up) + matrix[m][n];

    }
};
