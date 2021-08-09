class NumMatrix {
public:
    vector<vector<int>> matrix;
    vector<vector<int>> prefixSum;
    
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        
        prefixSum = vector<vector<int>> (matrix.size(), vector<int> (matrix[0].size()));
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                prefixSum[i][j] = matrix[i][j];
                if(i>0){
                    prefixSum[i][j] += prefixSum[i-1][j];
                }
                if(j>0){
                    prefixSum[i][j] += prefixSum[i][j-1];
                }
                if(i>0 and j>0){
                    prefixSum[i][j] -= prefixSum[i-1][j-1];
                }
            }
        }
    }
    
    int getSum(int row, int col){
        if(row<0 or col<0) return 0;
        
        return prefixSum[row][col];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
     
        return getSum(row2, col2) - getSum(row2, col1-1) - getSum(row1-1, col2) + getSum(row1-1, col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
