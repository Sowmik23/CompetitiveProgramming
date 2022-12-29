class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int> (n, 1));

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

//2nd time
class Solution {
public:
    long mod = (2 * 1e9) + 1;
    int uniquePaths(int m, int n) {

        vector<vector<int>> memo(m, vector<int> (n, 0));

        return dp(memo, m, n, 0, 0);
    }
private:
    int dp(vector<vector<int>> &memo, int m, int n, int i, int j){

        if(i>=m or j>=n) return 0;
        if(i==m-1 and j==n-1) return 1;
        if(memo[i][j]!=0) return memo[i][j];

        memo[i][j] = (dp(memo, m, n, i+1, j)%mod + dp(memo, m, n, i, j+1))%mod;

        return memo[i][j]%mod;
    }
};
