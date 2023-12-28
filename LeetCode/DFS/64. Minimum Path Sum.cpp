64. Minimum Path Sumclass Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        //recursive
        // return dfs(grid, 0, m-1, n-1);

        //recursion with memo
        vector<vector<int>> memo(m, vector<int> (n, -1));
        return recursionWithMemo(grid, memo, m-1, n-1);
    }
private:
    int dfs(vector<vector<int>> &grid, int sum, int m, int n){
        if(m==0 and n==0){
            return sum+grid[0][0];
        }
        if(m<0 or n<0) return INT_MAX;
        sum+=grid[m][n];

        return min(dfs(grid, sum, m-1, n), dfs(grid, sum, m, n-1));
    }
    long recursionWithMemo(vector<vector<int>> &grid, vector<vector<int>> &memo, int m, int n){
        if(m==0 and n==0) {
            return grid[0][0];
        }
        if(m<0 or n<0) return INT_MAX;
        if(memo[m][n]!=-1) return memo[m][n];

        //sum+=grid[m][n];
        memo[m][n] = min(grid[m][n]+recursionWithMemo(grid, memo, m-1, n), grid[m][n]+recursionWithMemo(grid, memo, m, n-1));
        return memo[m][n];
    }
};