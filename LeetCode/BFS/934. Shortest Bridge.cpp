// 934. Shortest Bridge
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        

        //Time: O(n^2)
        //Space: O(n)
        int n = grid.size();
        int startX, startY;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    startX = i;
                    startY = j;
                    break;
                }
            }
        }

        vector<pair<int, int>> groupAList;
        dfs(grid, groupAList, startX, startY);

        int brize_size = 0;
        while(groupAList.size()>0){
            vector<pair<int,int>> tmpList;
            for(auto& pa: groupAList){
                int x = pa.first;
                int y = pa.second;
                for(int i=0;i<4;i++){
                    int xx = x+directions[i];
                    int yy = y+directions[i+1];
                    if(xx>=0 and xx<n and yy>=0 and yy<n){
                        if(grid[xx][yy]==1) return brize_size;
                        else if(grid[xx][yy]==0){
                            tmpList.push_back({xx, yy});
                            grid[xx][yy] = -1; //to unvisite again
                        }
                    }
                }
            }
            groupAList = tmpList;
            brize_size++;
        }

        return brize_size;
    }
private:
    int directions[5] = {1, 0, -1, 0, 1};
    void dfs(vector<vector<int>> &grid, vector<pair<int, int>> &groupAList, int startX, int startY){
        groupAList.push_back({startX, startY});
        grid[startX][startY] = 2;

        for(int i=0;i<4;i++){
            int xx = startX+directions[i];
            int yy = startY+directions[i+1];
            if(xx>=0 and xx<grid.size() and yy>=0 and yy<grid.size() and grid[xx][yy]==1){
                dfs(grid, groupAList, xx, yy);
            }
        }
    }
};