class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        // Think this sorted matrix as sorted array
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int left = 0;
        int right = row*col - 1;
        
        while(left<=right){
            int mid = (left+right)/2;
            
            if(matrix[mid/col][mid%col]==target) return true;
            
            if(matrix[mid/col][mid%col]<target){
                left = mid+1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
