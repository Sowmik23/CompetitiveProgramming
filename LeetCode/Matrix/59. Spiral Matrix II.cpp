class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int start_row = 0;
        int start_col = 0;
        int end_row = n-1;
        int end_col = n-1;
        
        vector<vector<int>> res(n, vector<int> (n, 0));
        
        int val = 1;
        
        while(start_row<=end_row and start_col<=end_col){
            
            for(int i=start_col;i<=end_col;i++){
                res[start_row][i] = val++;
            }
            
            for(int i=start_row+1;i<=end_row;i++){
                res[i][end_col] = val++;
            }
            
            if(start_row<end_row and start_col<end_col){
                  for(int i=end_col-1;i>start_col;i--){
                      res[end_row][i] = val++;
                  }

                  for(int i = end_row;i>start_row;i--){
                      res[i][start_col] = val++;
                  }
            }
            start_row++;
            end_row--;
            start_col++;
            end_col--;
        }
        
        return res;
    }
};
