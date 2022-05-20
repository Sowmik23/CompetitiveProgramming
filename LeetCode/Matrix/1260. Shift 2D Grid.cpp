class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> res(m, vector<int> (n, 0));
        
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val = grid[i][j];
                
                int a = i;
                int b = (j+k);
                if(b>=n) {
                    a+=(b/n);
                    b = b%n;
                }
                if(a>=m) a = a%m;
                
                res[a][b] = val;
            }
        }
        
        return res;
    }
};
