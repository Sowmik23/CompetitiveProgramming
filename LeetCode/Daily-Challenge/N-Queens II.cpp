class Solution {
public:
    int ans=0;
    int totalNQueens(int n) {
     
        
        vector<string> grid;
        string str;
        
        for(int i=0;i<n;i++){
            str += ".";
        }
        for(int i=0; i<n;i++){
            grid.push_back(str);
        }
        
        backtrack(grid, 0, n);
        return ans;
    }
    
    
private:
    void backtrack(vector<string> &grid, int column, int n) {
        if(column==n){
            ans++;
            return;  
        } 
        for(int i=0;i<n;i++){
            if(isPossible(grid, i, column, n)){
                grid[i][column] = 'Q';
              
                backtrack(grid, column+1, n);
                grid[i][column] = '.';
            }
        }
    }
    
    bool isPossible(vector<string> &grid, int row, int col, int n){
    
        ///checking columns
        for(int i=0;i<col;i++){
            if(grid[row][i ]=='Q') return false;
        }
        
        ///checking upper left diagonal: as we fill columnwise
        for(int i=row-1, j=col-1;i>=0 and j>=0;i--, j--){

            if(grid[i][j]=='Q') return false;
        }
        
        ///checking lower left diagonal
        for(int i=row+1, j=col-1;i<n and j>=0;i++, j--){

            if(grid[i][j]=='Q') return false;
        }
        
        return true;
    }
};
