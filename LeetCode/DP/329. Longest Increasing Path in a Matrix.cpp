class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
     
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> visited(m, vector<int> (n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x = dfs_visit(matrix, visited, i, j);
                //cout<<"Value of x: "<<x<<endl;
                res = max(res, x+1);
            }
        }
        
        return res;
    }
private:
    int directionX[4]  = {1, 0, -1, 0};
    int directionY[4]  = {0, 1, 0, -1};
    int dfs_visit(vector<vector<int>> &matrix, vector<vector<int>> &visited, int i, int j){
        
        if(visited[i][j]) return visited[i][j];
     
       // cout<<matrix[i][j]<<endl;
        
        int mx = 0;
        for(int k=0;k<4;k++){
            int x = i+directionX[k];
            int y = j+directionY[k];
            
            if((x>=0 and x<matrix.size() and y>=0 and y<matrix[x].size()) and matrix[i][j]>matrix[x][y]){
                int l =  1+dfs_visit(matrix, visited, x, y);
                mx = max(mx, l);
            }
        }
        visited[i][j] = mx;
        
        return visited[i][j];
    }
};
