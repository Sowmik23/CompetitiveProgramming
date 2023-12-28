class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int, int>>> graph(n);
        for(auto& f: flights){
            graph[f[0]].push_back({f[1], f[2]});
        }

        //using dijkstra
        //return dijkstra(graph, src, dst, k, n);

        //using bfs
        return bfs(graph, src, dst, k, n);
    }
private:
    int bfs(vector<vector<pair<int, int>>> &graph, int src, int dst, int k, int size){
        vector<int> distance(size, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        distance[src] = 0;
        int stations = 0;
        while(!q.empty() and stations<=k){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto tmp = q.front();
                q.pop();
                int u = tmp.first;
                int cost = tmp.second;
                for(auto& f: graph[u]){
                    int v = f.first;
                    int dist = f.second;
                    if(distance[v]>cost+dist){
                        distance[v] = cost+dist;
                        q.push({v, distance[v]});
                    }
                }
            }
            stations++;
        }
        return distance[dst]==INT_MAX ? -1 : distance[dst];
    }
    int dijkstra(vector<vector<pair<int,int>>> &graph, int src, int dst, int k, int n){

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> stops(n, INT_MAX);
        pq.push({0, src, 0}); //distance, src, steps

        while(!pq.empty()){
            auto tmp = pq.top();
            pq.pop();
            int dist = tmp[0];
            int u = tmp[1];
            int stp = tmp[2];

            if(stp>stops[u] or stp>k+1) continue;
            stops[u] = stp;
            if(u==dst) return dist;
            for(auto& f: graph[u]){
                int v = f.first;
                int cost = f.second;
                pq.push({dist+cost, v, stp+1});
            }
        }
        return -1;
    }
};
