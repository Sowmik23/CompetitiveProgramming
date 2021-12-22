class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int j=n-1, i = 0;
        while(j>=0 and i<m){
            
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target) j--;
            else if(matrix[i][j]<target) i++;
        }
        
        return false;
    }
};
