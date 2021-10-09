class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        int n = 34;
        vector<vector<int>> pascalsTriangle(n);
        
        for(int i=0;i<n;i++){
            pascalsTriangle[i].resize(i+1);
            
            pascalsTriangle[i][i] = 1;
            pascalsTriangle[i][0] = 1;
            
            for(int j =1;j<i;j++){
                pascalsTriangle[i][j] = pascalsTriangle[i-1][j-1] + pascalsTriangle[i-1][j];
            }
        }
        
        return pascalsTriangle[rowIndex];
    }
};
