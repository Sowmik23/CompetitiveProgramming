class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
     
        int m = grid.size();
        int n = grid[0].size();
        int total_orange = 0;
        queue<pair<int, int>> rotten_oranges;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) rotten_oranges.push({i,j});
                if(grid[i][j]!=0) total_orange++;
            }    
        }
        
        int row[] = { 1, 0, -1, 0};
        int col[] = {0, -1, 0, 1};
        
        int cnt = 0, time = 0;
        while(!rotten_oranges.empty()){
            
            int k = rotten_oranges.size();
            cnt+=k;
            while(k--){
                pair<int, int> top = rotten_oranges.front();
                rotten_oranges.pop();
                
                int x = top.first;
                int y = top.second;
                
                
                for(int i=0;i<4;i++){
                    int posX = x + row[i];
                    int posY = y + col[i];
                    if(posX>=0 and posY>=0 and posX<m and posY<n and grid[posX][posY]==1){
                        grid[posX][posY] = 2;
                        rotten_oranges.push({posX, posY});
                    }
                }
            }
            if(rotten_oranges.size()>0) time++;
        }
        if(cnt!=total_orange) return -1;
        
        return time;
    }
};
