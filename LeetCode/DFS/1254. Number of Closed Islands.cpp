// 1254. Number of Closed Islands
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
       
        for(int i=0;i<m;i++){
             //left
            if(grid[i][0]==0){
                dfs_visit(grid, i, 0);
            }
            //right
            if(grid[i][n-1]==0){
                dfs_visit(grid, i, n-1);
            }
        }
       
        for(int i=0;i<n;i++){
            //up
            if(grid[0][i]==0){
                dfs_visit(grid, 0, i);
            }
            //down
            if(grid[m-1][i]==0){
                dfs_visit(grid, m-1, i);
            }
        }

        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    cnt++;
                    dfs_visit(grid, i, j);
                }
            }
        }
        return cnt;
    }
private:
    vector<int> directions = {1, 0, -1, 0, 1};
    void dfs_visit(vector<vector<int>> &grid, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 1;
        
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0;k < sz;k++){
                auto top = q.front();
                q.pop();

                int ii = top.first;
                int jj = top.second;
                for(int l=0;l<4;l++){
                    int x = directions[l]+ii;
                    int y = directions[l+1]+jj;
                    if((x>=0 and x<grid.size() and y>=0 and y<grid[0].size()) and grid[x][y]==0){
                        grid[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }
    }
};