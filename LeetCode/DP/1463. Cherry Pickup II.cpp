class Solution {
public:
    int memo[71][71][71];
    
    int cherryPickup(vector<vector<int>>& grid) {
     
        //Dynamic programming: with memoization
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    memo[i][j][k] = -1;
                }
            }
        }
        
        
        return dp(0, 0, n-1, grid);
    }
    
private:
    int dp(int i, int j, int k, vector<vector<int>> &grid){
        if(i>=grid.size() or j<0 or j>=grid[i].size() or k<0 or k>=grid[i].size()) return 0;
        
        if(memo[i][j][k]!=-1) return memo[i][j][k];
        
        //current
        int res = 0;
        
        res+=grid[i][j];
        if(j!=k){
            res+=grid[i][k];
        }
        
        if(i!=grid.size()-1){
            int mx = 0;
            
            for(int newCol1 = j-1;newCol1<=j+1;newCol1++){
                for(int newCol2=k-1;newCol2<=k+1;newCol2++){
                    mx = max(mx, dp(i+1, newCol1, newCol2, grid));    
                }
            }
            
            res+=mx;
        }
        
        memo[i][j][k] = res;
        return res;
    }
};
