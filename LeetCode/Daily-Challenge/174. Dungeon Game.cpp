class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        //recursion
        // return dp(0, 0, dungeon);
        
        //recursion with memoization : 
        // vector<vector<int>> memo(dungeon.size()+2, vector<int> (dungeon[0].size()+2, 1e9+5));
        // return dpWithMemoization(0, 0, dungeon, memo);
        
        //Tabulation
        return dpTabulation(dungeon);
    }
private:
    int dp(int i, int j, vector<vector<int>> &dungeon){
        
        if(i>=dungeon.size() or j>=dungeon[0].size()) return 1e9+5;
        
        if(i==dungeon.size()-1 and j==dungeon[0].size()-1) {
            if(dungeon[i][j]<0) return -dungeon[i][j]+1;
            else return 1;
        }
        
        int goDown = dp(i+1, j, dungeon);
        int goRight = dp(i, j+1, dungeon);
        
        int life = min(goRight, goDown) - dungeon[i][j];
        if(life<=0) return 1;
        return life;
    }
    
    int dpWithMemoization(int i, int j, vector<vector<int>> &dungeon, vector<vector<int>> &memo)     {
        if(i>=dungeon.size() or j>=dungeon[0].size()) return 1e9+5;
        if(i==dungeon.size()-1 and j==dungeon[0].size()-1){
            if(dungeon[i][j]<0) return -dungeon[i][j]+1;
            else return 1;
        }
        
        if(memo[i][j]!=1e9+5) return memo[i][j];
        
        int down = dpWithMemoization(i+1, j, dungeon, memo);
        int right = dpWithMemoization(i, j+1, dungeon, memo);
        
        int res = min(down, right)-dungeon[i][j];
        
        if(res<=0) res = 1;
        memo[i][j] = res;
        
        return res;
    }
    
    int dpTabulation(vector<vector<int>> &dungeon){
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> memo(m+2, vector<int> (n+2, 1e9+5));
        
        memo[m-1][n] = 1;
        memo[m][n-1] = 1;
            
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
                int res = min(memo[i][j+1], memo[i+1][j]) - dungeon[i][j];
                
                if(res<=0) memo[i][j] = 1;
                else memo[i][j] = res;
            }
        }
        
        return memo[0][0];
    }
};
