// 1129. Shortest Path with Alternating Colors
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        //BFS
        vector<vector<pair<int, int>>> graph(n);
        for(auto edges: redEdges){
            graph[edges[0]].push_back({edges[1], 1}); //1 for red edges
        }
        for(auto edges: blueEdges){
            graph[edges[0]].push_back({edges[1], 0}); //0 for blue edges
        }

        vector<int> dist(n, -1);
        vector<vector<bool>> visited(n, vector<bool> (2,false));
        queue<vector<int>> q;
        q.push({0, -1, 0});    
        
        visited[0][0] = visited[0][1] = true;
        dist[0] = 0;

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto top = q.front();
                q.pop();
                int u = top[0];
                int prevColor = top[1];
                int level = top[2];

                for(auto [v, color]: graph[u]){
                    if(prevColor!=color and !visited[v][color]){
                        q.push({v, color, level+1});
                        visited[v][color] = true;
                        if(dist[v]==-1) dist[v] = 1+level;
                    }
                }
            }
        }
        return dist;
    }
};