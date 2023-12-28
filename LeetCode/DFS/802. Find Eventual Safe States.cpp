// 802. Find Eventual Safe States
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        //topological sorting: Kahn's algorithm
        /*
        int n = graph.size();
        vector<vector<int>> gh(n);
        vector<int> indegree(n, 0);

        for(int i=0;i<n;i++){
            for(auto& node: graph[i]){
                gh[node].push_back(i);
                indegree[i]++;
            }
        }

        // vector<int> safeNodes;
        vector<bool> safeNodes(n, false);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            // safeNodes.push_back(top);
            safeNodes[top] = true;
            for(auto& nei: gh[top]){
                indegree[nei]--;
                if(indegree[nei]==0) q.push(nei);
            }
        }
        //sort(safeNodes.begin(), safeNodes.end());

        vector<int> res;
        for(int i=0;i<n;i++) if(safeNodes[i]) res.push_back(i);

        // return safeNodes;
        return res;
        */


        //using dfs
        //Time: O(V+E)
        int n = graph.size();
        vector<int> res;
        vector<bool> inStack(n, false);
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(auto& node: graph[i]){
                adj[i].push_back(node);
            }
        }

        for(int i=0;i<n;i++){
            bool isSafe = dfs(i, adj, inStack, visited);
            if(!isSafe) res.push_back(i);
        }
       
        return res;
    }
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &inStack, vector<bool> &visited){
        
        if(inStack[node]) return true; //contains cycle: unsafe node
        if(visited[node]) return false; //safe node

        visited[node] = true;
        inStack[node] = true;
        for(auto& neighbor: adj[node]){

            if(dfs(neighbor, adj, inStack, visited)) return true; //unsafe node
        }
        inStack[node] = false; //mark it out of stack

        return false; //safe node
    }
};





