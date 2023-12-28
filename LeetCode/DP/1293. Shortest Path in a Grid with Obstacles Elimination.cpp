class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        // // recursion: TLE
        // vector<vector<int>> visited(m, vector<int> (n, 0));
        // int res = recursive(grid, visited, m, n, k, m-1, n-1);
        // if(res>m*n) return -1;
        // return res;

        // recursion with memoizatoin: Accepted
        vector<vector<int>> visited(m+1, vector<int> (n+1, 0));
        vector<vector<vector<int>>> memo(m+1, vector<vector<int>> (n+1,  vector<int> (k+5, -1)));
        int res = recursionWithMemo(grid, visited, memo, m, n, k, m-1, n-1);
        if(res>=m*n) return -1;
        return res;

    }
private:
    int recursive(vector<vector<int>> &grid, vector<vector<int>> &visited, int m, int n,int k, int i, int j){

        if(i==0 and j==0) return 0;
        if(i<0 or i>=m or j<0 or j>=n or visited[i][j]) return 99999;

        if(grid[i][j]==1) {
            if(k>0) k--;
            else return 99999;
        }
        visited[i][j] = 1;
        int right = 1+recursive(grid, visited, m, n, k, i+1, j);
        int left = 1+recursive(grid, visited, m, n, k, i-1, j);
        int up = 1+recursive(grid, visited, m, n, k, i, j+1);
        int down = 1+recursive(grid, visited, m, n, k, i, j-1);
        visited[i][j] = 0;
        return min({right, left, up, down});
    }

    int recursionWithMemo(vector<vector<int>> &grid, vector<vector<int>> &visited, vector<vector<vector<int>>> &memo, int m, int n,int k, int i, int j){

        if(i<0 or i>=m or j<0 or j>=n or visited[i][j]) return 99999;
        if(i==0 and j==0) return memo[i][j][k] = 0;
        if(memo[i][j][k]!=-1) return memo[i][j][k];

        if(grid[i][j]==1) {
            if(k>0) k--;
            else return memo[i][j][k] = 99999;
        }

        visited[i][j] = 1;

        int left = 1+recursionWithMemo(grid, visited, memo, m, n, k, i, j-1);
        int right = 1+recursionWithMemo(grid, visited, memo, m, n, k, i, j+1);
        int up = 1+recursionWithMemo(grid, visited, memo, m, n, k, i-1, j);
        int down = 1+recursionWithMemo(grid, visited, memo, m, n, k, i+1, j);

        visited[i][j] = 0;

        return memo[i][j][k] = min({left,right, up, down});
    }
};
 
