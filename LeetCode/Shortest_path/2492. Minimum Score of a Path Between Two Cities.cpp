// 2492. Minimum Score of a Path Between Two Cities
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        //Dijkstra
        for(auto& road: roads){
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        dijkstra(1, n);
        return res;
    }
private:
    vector<vector<int>> graph[100005];
    int res = INT_MAX;
    void dijkstra(int x, int n){

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({x, 0});
        dist[x] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int u = top.first;
            for(auto& g: graph[u]){
                int v = g[0];
                int d = g[1];
                res = min(res, d);
                if(dist[v]>dist[u]+d){
                    dist[v] = dist[u]+d;
                    pq.push({v, dist[v]});
                }
            }
        }
        
    }
};