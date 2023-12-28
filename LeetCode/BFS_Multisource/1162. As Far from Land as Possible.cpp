// 1162. As Far from Land as Possible
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        //multisource bfs
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int> (n));
        queue<pair<int, int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                }
                visited[i][j] = grid[i][j];
            }
        }

        int directions[5] = {1, 0, -1, 0, 1};
        int dist = -1;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto top = q.front();
                q.pop();
                
                for(int k=0;k<4;k++){
                    int x = top.first + directions[k];
                    int y = top.second + directions[k+1];

                    if((x>=0 and x<grid.size() and y>=0 and y<grid[0].size()) and visited[x][y]==0){
                        q.push({x, y});
                        visited[x][y] = 1;
                    }
                }
            }
            dist++;
        }

        return dist==0 ? -1 : dist;
    }
};