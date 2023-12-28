class Solution {
public:
    int empt = 1, res = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {

        int startX, startY;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    startX = i;
                    startY = j;
                }
                else if(grid[i][j]==0) empt++;
            }
        }

        dfs(grid, startX, startY, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>> &grid, int i, int j, int cnt){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]==-1) return;

        if(grid[i][j]==2){
            cout<<cnt<<" "<<empt<<endl;
            if(cnt==empt) res++;
            return;
        }
        grid[i][j] = -1;

        dfs(grid, i+1, j, cnt+1);
        dfs(grid, i-1, j, cnt+1);
        dfs(grid, i, j+1, cnt+1);
        dfs(grid, i, j-1, cnt+1);

        grid[i][j] = 0;
        return;
    }
};
