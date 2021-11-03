class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        //TLE
//         int lefti = 0, leftj = 0, righti=matrix.size()-1, rightj = matrix[0].size()-1;
        
//         while(lefti<=righti and leftj<=rightj and righti>=0 and rightj>=0){
//             int midi = lefti+(righti-lefti)/2;
//             int midj = leftj+(rightj-leftj)/2;
            
//             int val = matrix[midi][midj];
//             if(val==target){
//                 return true;
//             }
//             if(val>target){
//                 righti = midi-1;
//                 rightj = midj-1;
//             }
//             else {
//                 lefti = midi;
//                 leftj = midj;
//             }
//         }
        
//         return false;
        
        
        //Time: O(n+m)
        //Space: O(1)
        
        int row = 0, col = n-1;
        
        while(row<m and col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        
        return false;
    }
};
