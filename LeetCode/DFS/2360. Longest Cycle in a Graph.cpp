// 2360. Longest Cycle in a Graph
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        
        //using dfs
        /*
        int n = edges.size();
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++){
            unordered_map<int, int> mp;
            mp[i] = 1;
            if(!visited[i]) dfs_visit(i, edges, visited, mp);
        }
        return res;
        */

        //using khan's algorithm
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> indegree(n, 0);
        for(auto& ed: edges){
            if(ed!=-1) indegree[ed]++;
        }

        //start khan's algo
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            visited[top] = true;
            int neighbour = edges[top];
            if(neighbour!=-1 and !visited[neighbour]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        //end of khan's algorithm

        int res = -1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int cnt = 1;
                int neighbour = edges[i];
                visited[i] = true;
                while(neighbour!=i){
                    visited[neighbour] = true;
                    neighbour = edges[neighbour];
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
private:
    int res = -1;
    void dfs_visit(int node, vector<int> &edges, vector<bool> &visited, unordered_map<int, int> &mp){
        visited[node] = true;
        int neighbour = edges[node];
        if(neighbour!=-1 and !visited[neighbour]){
            mp[neighbour] = mp[node]+1;
            dfs_visit(neighbour, edges, visited, mp);
        }
        else if(neighbour!=-1 and mp[neighbour]>0){
            res = max(res, mp[node]-mp[neighbour]+1);
        }
    }
};