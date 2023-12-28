// 2328. Number of Increasing Paths in a Grid
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        memo = vector<vector<int>> (m, vector<int> (n, -1));
        int cnt = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cnt = (cnt+dfs(grid, i, j))%mod;
            }
        }
        return cnt;
    }
private:
    int mod = 1e9+7;
    vector<vector<int>> memo;
    vector<int> directions = {1, 0, -1, 0, 1};
    int dfs(vector<vector<int>> &grid, int i, int j){

        if(memo[i][j]!=-1) return memo[i][j];
        int cnt = 1;

        for(int k=0;k<4;k++){
            int xx = i+directions[k];
            int yy = j+directions[k+1];
            if(xx>=0 and xx<grid.size() and yy>=0 and yy<grid[0].size() and grid[xx][yy]<grid[i][j]){
                cnt+=dfs(grid, xx, yy);
                cnt%=mod;
            }
        }
        return memo[i][j] = cnt%mod;
    }
};