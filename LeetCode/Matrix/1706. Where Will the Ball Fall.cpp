class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {

        vector<int> res;
        int m = grid.size();
        int n = grid[0].size();

        int i = 0, j = 0;
        for(int i=0;i<n;i++){
            res.push_back(process(grid, 0, i));
        }
        return res;
    }
private:
    int process(vector<vector<int>> &grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        while(i>=0){
            if(grid[i][j]==1){
                if(j+1>=n or grid[i][j+1]==-1) return -1;
                else {
                    i = i+1;
                    j = j+1;
                }
            }
            else {
                if(j-1<0 or grid[i][j-1]==1) return -1;
                else {
                    i = i+1;
                    j = j-1;
                }
            }

            if(i>=m) {
                return j;
            }
        }
        return -1;
    }
};
