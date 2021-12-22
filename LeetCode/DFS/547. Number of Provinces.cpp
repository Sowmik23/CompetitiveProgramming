class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<bool> visited(n, false);
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs_visit(isConnected, visited, i);
                cnt++;
            }
        }
        
        return cnt;
    }
private:
    void dfs_visit(vector<vector<int>> &isConnected, vector<bool> &visited, int i){
        
        visited[i] = true;
        for(int j=0;j<isConnected[i].size();j++){
            if(isConnected[i][j]==1 and !visited[j]){
                dfs_visit(isConnected, visited, j);
            }
        }
    }
};
