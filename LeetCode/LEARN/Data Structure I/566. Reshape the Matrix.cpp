class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        
        int m = mat.size();
        int n = mat[0].size();
        
        
        vector<vector<int>> res;
        vector<int> tmp;
        
        if(m*n!=r*c) return mat;
        else {
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    tmp.push_back(mat[i][j]);
                    if(tmp.size()==c){
                        res.push_back(tmp);
                        tmp = vector<int> ();
                    }
                }
            }
        }
        
        return res;
    }
};
