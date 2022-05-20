class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
     
        vector<vector<int>> res;
        
        vector<vector<int>> graph(n);
        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        
        vector<bool> visited(n, false);
        vector<int> disc(n);
        vector<int> low(n);
        vector<int> parent(n, -1);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs_visit(i, graph, res, visited, disc, low, parent);
            }
        }
        
        return res;
    }
private:
    void dfs_visit(int x, vector<vector<int>> &graph, vector<vector<int>> &res, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent){
        
        static int time = 0;
	
        visited[x] = true;
        disc[x] = low[x] = time++;

        for(auto i=graph[x].begin();i!=graph[x].end();i++){
            int y = *i;

            if(!visited[y]){
                parent[y] = x;
                dfs_visit(y, graph, res, visited, disc, low, parent);

                low[x] = min(low[x], low[y]);

                //if lowest vertex reachable from subtree under y is below
                //x	in dfs tree, then x-y is a bridge.
                
                if(low[y]>disc[x]){
                    res.push_back({x, y});
                    // cout<<x<<" "<<y<<endl;
                }
            }
            else if(y!=parent[x]){
                low[x] = min(low[x], disc[y]);
            }
        }
    }
};
