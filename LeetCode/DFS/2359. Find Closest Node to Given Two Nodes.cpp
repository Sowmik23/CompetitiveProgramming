class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        int n = edges.size();
        vector<bool> visited1(n, false), visited2(n, false);
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        vector<vector<int>> graph(n);

        for(int i=0;i<n;i++){
            graph[i].push_back(edges[i]);
        }

        dist1[node1] = 0;
        dist2[node2] = 0;
        dfs(graph, visited1, dist1, node1);
        dfs(graph, visited2, dist2, node2);

        int maxDisTillNow = INT_MAX, closestNode = -1;
        for(int i=0;i<n;i++){
            if(maxDisTillNow>max(dist1[i], dist2[i])){
                closestNode = i;
                maxDisTillNow = max(dist1[i], dist2[i]);
            }
        }
        return closestNode;
    }
private:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &dist, int node){
        visited[node] = true;
        for(auto& n: graph[node]){
            if(n!=-1 and visited[n]==false){
                dist[n] = 1+dist[node];
                dfs(graph, visited, dist, n);
            }
        }
    }
};
