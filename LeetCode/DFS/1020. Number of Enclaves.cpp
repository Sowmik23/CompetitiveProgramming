// 1020. Number of Enclaves
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            //left
            if(grid[i][0]==1) dfs_visit(grid, i, 0);
            //right
            if(grid[i][n-1]==1) dfs_visit(grid, i, n-1);
        }
        for(int i=0;i<n;i++){
            //up
            if(grid[0][i]==1) dfs_visit(grid, 0, i);
            //down
            if(grid[m-1][i]==1) dfs_visit(grid, m-1, i);
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt+=dfs_visit(grid, i, j);
                }
            }
        }
        return cnt;
    }
private:
    vector<int> directions = {1, 0, -1, 0, 1};
    int dfs_visit(vector<vector<int>> &grid, int i, int j){

        int cnt = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        while(!q.empty()){
            int sz = q.size();
            cnt+=sz;
            for(int k=0;k<sz;k++){
                auto top = q.front();
                q.pop();

                int ii = top.first;
                int jj = top.second;
                for(int l=0;l<4;l++){
                    int x = directions[l]+ii;
                    int y = directions[l+1]+jj;
                    if((x>=0 and x<grid.size() and y>=0 and y<grid[0].size()) and grid[x][y]==1){
                        grid[x][y] = 0;
                        q.push({x, y});
                    }
                }
            }
        }
        return cnt;
    }
};