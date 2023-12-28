// 2482. Difference Between Ones and Zeros in Row and Column
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, pair<int, int>> rowMap, colMap;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                auto [rzero, rone] = rowMap[i];
                auto [czero, cone] = colMap[j];

                if(grid[i][j]==0) {
                    rzero++;
                    czero++;
                }
                else {
                    rone++;
                    cone++;
                }
                rowMap[i] = {rzero, rone};
                colMap[j] = {czero, cone};
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x = rowMap[i].second + colMap[j].second - rowMap[i].first - colMap[j].first;
                grid[i][j] = x;
            }
        }
        return grid;
    }
};