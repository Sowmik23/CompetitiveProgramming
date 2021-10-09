class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int rowStart = 0;
        int rowEnd = n-1;
        
        int colStart = 0;
        int colEnd = n-1;
        
        vector<vector<int>> res(n, vector<int> (n,0));
        int x = 1;
        
        while(rowStart<=rowEnd and colStart<=colEnd){
            
            for(int i=colStart;i<=colEnd;i++){
                res[rowStart][i] = x++;
            }
            for(int i=rowStart+1;i<=rowEnd;i++){
                res[i][colEnd] = x++;
            }
            
            if(rowStart<rowEnd and colStart<colEnd){
                for(int i=colEnd-1;i>colStart;i--){
                    res[rowEnd][i] = x++;
                }
                for(int i=rowEnd;i>rowStart;i--){
                    res[i][colStart] = x++;
                }
            }
            
            rowStart++;
            colStart++;
            rowEnd--;
            colEnd--;
        }
        
        return res;
    }
};
