// 1727. Largest Submatrix With Rearrangements

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!=0 and i>0){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }

            vector<int> currRow = matrix[i];
            sort(currRow.begin(), currRow.end(), greater());
            for(int j=0;j<n;j++){
                res = max(res, currRow[j]*(j+1));
            }
        }
        return res;
    }
};