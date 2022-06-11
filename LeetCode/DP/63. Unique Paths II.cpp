class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        if(obstacleGrid[0][0]==1 or obstacleGrid[m-1][n-1]==1) return 0;
        
        return dfs_visit(obstacleGrid, dp, 0, 0);
    }
private:
    int right;
    int down;
    int dfs_visit(vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp, int i, int j){
        
        if(i>=obstacleGrid.size() or j>=obstacleGrid[0].size() or obstacleGrid[i][j]==1) return 0;
        if(i==obstacleGrid.size()-1 and j==obstacleGrid[0].size()-1) return 1;
        
        if(dp[i][j]) return dp[i][j];
        
        int right = dfs_visit(obstacleGrid, dp, i, j+1);
        int down = dfs_visit(obstacleGrid, dp, i+1, j);
        
        int total = right + down;
        dp[i][j] = total;
        
        return total;
    }
};
