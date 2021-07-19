class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        
        int m = mat.size();
        int n = mat[0].size();
        
        if(m*n!=r*c){
            return mat;
        }
        
        vector<vector<int>> res;
        vector<int> tmp;
        
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            
            for(int j=0;j<mat[i].size();j++){
                tmp.push_back(mat[i][j]);
                cnt++;
                
                if(cnt==c){
                    res.push_back(tmp);
                    tmp = vector<int> ();
                    cnt = 0;
                }
            }
        }
        
        return res;
    }
};
