// 6330. Shortest Cycle in a Graph

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(n);
        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int res = INT_MAX;
        
        for(int i=0;i<n;i++){
            
            vector<int> dist(n, INT_MAX);
            vector<int> parent(n, -1);
            dist[i] = 0;
            queue<int> q;
            q.push(i);
            
            while(!q.empty()){
                int top = q.front();
                q.pop();
                for(auto& child: graph[top]){
                    if(dist[child]==INT_MAX){
                        dist[child] = 1+dist[top];
                        parent[child] = top;
                        q.push(child);
                    }   
                    else if(parent[top]!=child and parent[child]!=top){
                        res = min(res, 1+dist[top]+dist[child]);
                    }
                }
            }
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};