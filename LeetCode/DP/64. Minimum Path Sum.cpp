// 64. Minimum Path Sum
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

       //recursion
       //return recursive(grid, m-1, n-1);

       //recursion with memoization
       //   vector<vector<int>> memo(m+1, vector<int> (n+1, -1));
       //   return recursionWithMemo(grid, memo, m-1, n-1);

        //tabulation
        vector<vector<int>> dp(m, vector<int> (n));
        
        //base case
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i=1;i<n;i++) dp[0][i] = dp[0][i-1] + grid[0][i];

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
private:
    int recursive(vector<vector<int>> &grid, int i, int j){
        if(i==0 and j==0) return grid[i][j];
        if(i<0 or j<0) return INT_MAX; //must be strictly less than 0
        
        return min(recursive(grid, i, j-1), recursive(grid, i-1, j)) + grid[i][j];
    }
    int recursionWithMemo(vector<vector<int>> &grid, vector<vector<int>> &memo, int i, int j){
        if(i==0 and j==0) return grid[0][0];
        if(i<0 or j<0) return INT_MAX;
        if(memo[i][j]!=-1) return memo[i][j];
        return memo[i][j] = min(recursionWithMemo(grid, memo, i-1, j), recursionWithMemo(grid, memo, i, j-1))+grid[i][j];
    }
};