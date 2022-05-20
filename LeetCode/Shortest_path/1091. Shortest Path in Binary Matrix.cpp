class Solution {
public:
    int res = INT_MAX;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        //dfs diye hobe na time limit khabe. so apply bfs
        //and find shortest path
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        int res = 0;
        
         // -1 -1
         // -1, 0
         //  0 -1   
         //  -1, 1
         //  1 0
         //  0 1
         //  1 1  
         //  1 -1
            
            
            
        int directionsX[8] = {-1, -1, 0, -1, 1, 0, 1, 1};
        int directionsY[8] = {-1, 0, -1, 1, 0, 1, 1, -1};
        
        while(!q.empty()){
            int dis = q.front().first;
            int topX = q.front().second.first;
            int topY = q.front().second.second;
            q.pop();

            if(grid[topX][topY]==1) continue;
     
            grid[topX][topY] = 1;
            dis++;
            
            if(topX==m-1 and topY==n-1) return dis;
            
            for(int i=0;i<8;i++){
                int x = topX+directionsX[i];
                int y = topY+directionsY[i];
                
                if(x>=0 and x<m and y>=0 and y<n and grid[x][y]==0){
                    q.push({dis, {x, y}});
                }
            }
            
        }
        
        return -1;
    }
private:
   
};
