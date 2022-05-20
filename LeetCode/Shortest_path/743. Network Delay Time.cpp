class Solution {
public:
    const int INF = INT_MAX;
    vector<pair<int, int>> graph[100+1];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //Approach-01: DIJKSTRA
        
        for(int i=0;i<times.size();i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        
        vector<int> distance(n+2, INF);
        
        dfs_visit(distance, n, k);
        
        int res = 0;
        for(int i=1;i<=n;i++){
            if(distance[i]==INF) return -1;
            res = max(res, distance[i]);
        }
        
        return res;
    }
private:
    void dfs_visit(vector<int> &distance, int n, int k){
        
        //problem: if there is a cycle in this graph and the path time is different
        //so need to apply  dijkstra
        
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        
        pq.push({k, 0});
        distance[k] = 0;
        
        while(!pq.empty()){
            int top = pq.top().first;
            pq.pop();
            
            for(auto& i: graph[top]){
                if(distance[i.first]>distance[top] + i.second){
                    distance[i.first] = distance[top] + i.second;
                    pq.push({i.first, distance[i.first]});
                }    
            }   
        }
    }
};
