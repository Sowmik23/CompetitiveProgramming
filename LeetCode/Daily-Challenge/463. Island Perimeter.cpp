class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i==0 or grid[i-1][j]==0) res++; //up
                    if(j==0 or grid[i][j-1]==0) res++; //left
                    if(i==m-1 or grid[i+1][j]==0) res++; //down
                    if(j==n-1 or grid[i][j+1]==0) res++; //right;
                }
            }
        }
        
        return res;
    }
};
