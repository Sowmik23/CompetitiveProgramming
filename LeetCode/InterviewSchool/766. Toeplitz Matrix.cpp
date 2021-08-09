class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0 and j>0 and matrix[i][j]!=matrix[i-1][j-1]) return false;
            }
        }
        return true;
        
        
        //Follow up:

        // What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
        // What if the matrix is so large that you can only load up a partial row into the memory at once?
        
        
        
        
    }
};
