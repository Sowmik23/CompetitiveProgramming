class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        //Problem: all possible topological sorting related but not
        
        vector<vector<int>> res;
        vector<int> path;
        
        dfs(graph, path, res, 0);
        
        return res;
    }
    
private:
    void dfs(vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &res, int curr){
        path.push_back(curr);
        if(curr==graph.size()-1){
            res.push_back(path);
        }
        else {
            for(auto& i: graph[curr]){
                dfs(graph, path, res, i);
            }
        }
        path.pop_back();
    }
};
