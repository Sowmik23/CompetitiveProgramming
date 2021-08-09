class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        
        ///Very much technical problem 
        int m = matrix.size();
        int n = matrix[0].size();
        bool isCol = false;
        
        for(int i=0;i<m;i++){
            
            if(matrix[i][0]==0) isCol = true;
            
            for(int j=1;j<n;j++){
                if(matrix[i][j] ==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==0 or matrix[i][0]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(matrix[0][0]==0){
            for(int j=0;j<n;j++) matrix[0][j] = 0;
        }
        
        if(isCol==true){
            for(int i=0;i<m;i++) matrix[i][0] = 0;
        }
    }
};
