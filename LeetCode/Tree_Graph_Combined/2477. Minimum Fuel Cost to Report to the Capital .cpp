class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size()+1;
        vector<vector<int>> graph(n);
        vector<int> degree(n);

        for(auto road: roads){
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
            degree[road[0]]++;
            degree[road[1]]++;
        }

        //dfs
        //dfs(graph, 0, -1, seats);

        //bfs
        queue<int> q;
        for(int i=1;i<n;i++) if(degree[i]==1) q.push(i); //push the leaf nodes into the queue
        vector<int> representative(n, 1);
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            fuel+=ceil((double)representative[top]/seats);
            for(auto& child: graph[top]){
                representative[child] +=representative[top];
                degree[child]--;
                if(degree[child]==1 and child!=0) q.push(child);
            }
        }

        return fuel;
    }
private:
    long long fuel = 0;
    long long dfs(vector<vector<int>> &graph, int src, int parent, int &seats){

        long long representative = 1; 
        for(auto& child: graph[src]){
            if(parent!=child){
                representative+=dfs(graph, child, src, seats);
            }
        }
        if(src!=0){
            fuel+=ceil((double)representative/seats);
        }

        return representative;
    }
};