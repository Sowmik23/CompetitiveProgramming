class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        int res = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] and grid[i][j]==1){
                    int c = dfs_visit(i, j, grid, visited);
                    res = max(res, c);
                }
            }
        }
        
        return res;
    }

private:
    int dfs_visit(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited){
        
        int row[] = {1, 0, -1, 0};
        int col[] = {0, -1, 0, 1};
        
        stack<pair<int, int>> stk;
        stk.push({x, y});
        int cnt = 0;
        
        while(!stk.empty()){
            
            pair<int, int> top = stk.top();
            stk.pop();
            
            x = top.first;
            y = top.second;
            
            if(!isValid(x, y, visited) or grid[x][y]!=1) continue;
            
            visited[x][y] = true;
            cnt++;
            
            for(int i=0;i<4;i++){
                int posX = x+row[i];
                int posY = y+col[i];
                
                stk.push({posX, posY});
            }
        }
        
        return cnt;
    }
    
    bool isValid(int x, int y, vector<vector<bool>> &visited){
        if(x<0 or y<0 or x>=visited.size() or y>=visited[0].size()) return false;
        if(visited[x][y]==true) return false;
        return true;
    }
};
