class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int row0 = 0, col0 = 0;
        int row1 = matrix.size()-1;
        int col1 = matrix[0].size()-1;
        
        vector<int> res;
        
        while(row0<=row1 and col0<=col1){
            
            for(int col = col0;col<=col1;col++){
                res.push_back(matrix[row0][col]);
            }
            for(int row = row0 + 1; row<=row1;row++){
                res.push_back(matrix[row][col1]);
            }
            
            if(row0 < row1 and col0<col1){
                for(int col = col1-1;col>col0;col--){
                    res.push_back(matrix[row1][col]);
                }
                
                for(int row=row1;row>row0;row--){
                    res.push_back(matrix[row][col0]);
                }
            }
            
            row0++;
            row1--;
            col0++;
            col1--;
        }
        
        return res;
    }
};
