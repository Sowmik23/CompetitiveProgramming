// 1466. Reorder Routes to Make All Paths Lead to the City Zero
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int, int>>> graph(n);
        for(auto& conn: connections){
            graph[conn[0]].push_back({conn[1], 1});
            graph[conn[1]].push_back({conn[0], 0}); //making virtual connection
        }

        dfs_visit(0, -1, graph); //dfs visit from 0th node
        return cnt;
    }
private:
    int cnt;
    void dfs_visit(int u, int parent, vector<vector<pair<int, int>>> &graph){

        for(auto& v: graph[u]){
            if(v.first!=parent){
                cnt+=v.second;
                dfs_visit(v.first, u, graph);
            }
        }
    }
};