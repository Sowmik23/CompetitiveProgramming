class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        //recursive: TLE
        // return recursive(obstacleGrid, m-1, n-1);

        //recursion with memoization
        // vector<vector<int>> memo(m+1, vector<int> (n, -1));
        // return recursionWithMemo(obstacleGrid, m-1, n-1, memo);

        //tabulation
        vector<vector<int>> dp(m+1, vector<int> (n+1));

        //base case
        //first position
        if(obstacleGrid[0][0]!=1) dp[0][0] = 1;
        // Because you can only arrive to dp[1][1] from dp[0][1] or dp[1][0], you can only set 
        // one of them as 1 so that dp[1][1] can be 1, which means when you at the 
        // obstacleGrid[0][0], there are only 1 path.
        
        // dp[0][1] = 1; or 
        dp[1][0] = 1;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(obstacleGrid[i-1][j-1]!=1){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else dp[i][j]= 0;
            }
        }
        return dp[m][n];
    }
private:
    int recursive(vector<vector<int>> &obstacleGrid, int i, int j){

        if(i<0 or j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 and j==0) return 1;

        return recursive(obstacleGrid, i-1, j) + recursive(obstacleGrid, i, j-1);
        // int taken = 0;
        // if(i-1>=0 and obstacleGrid[i-1][j]==0) taken = recursive(obstacleGrid, i-1, j);
        // if(j-1>=0 and obstacleGrid[i][j-1]==0) taken+= recursive(obstacleGrid, i, j-1);
        // return taken;
    }
    int recursionWithMemo(vector<vector<int>> &obstacleGrid, int i, int j, vector<vector<int>> &memo){
        if(i<0 or j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 and j==0) return 1;
        if(memo[i][j]!=-1) return memo[i][j];

        return memo[i][j] = recursionWithMemo(obstacleGrid, i-1, j, memo) + recursionWithMemo(obstacleGrid, i, j-1, memo);
    }
};


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
