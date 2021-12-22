class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][0]==1 or grid[m-1][n-1]==1) return -1;
        
        
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        int x[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int y[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        int cnt = 0;
        
        while(!q.empty()){
            
            cnt++;
            int size = q.size();
            
            for(int i=0;i<size;i++){
                pair<int, int> top = q.front();
                q.pop();

                if(top.first==m-1 and top.second==n-1) return cnt;

                for(int i=0;i<8;i++){
                    int xx = top.first + x[i];
                    int yy = top.second + y[i];

                    if(xx<m and yy<n and xx>=0 and yy>=0 and grid[xx][yy]==0 and visited[xx][yy]==false){
                        visited[xx][yy] = true;
                        q.push({xx, yy});
                    }
                }
            }
        }
        
        return -1;
    }
};
