class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        int mx = 0;
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int k = dfs_visit(i, j, m, n, dp, matrix);
                mx = max(mx, k);
            }
        }
        
        return mx;
    }
private:
    int dfs_visit(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &matrix){
        
        if(dp[i][j]!=0) return dp[i][j]; //memoization
        
        int cnt = 1;
        int row_col[] = {0, 1, 0, -1, 0};
        for(int k=0;k<4;k++){
            int x = i+row_col[k];
            int y = j+row_col[k+1];
            
            if(x<0 or y<0 or x>=m or y>=n or matrix[i][j]>=matrix[x][y]) continue;
            cnt = max(cnt, dfs_visit(x, y, m, n, dp, matrix)+1);
        }
        
        dp[i][j] = cnt;
        return cnt;
    }
};
