// 815. Bus Routes

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        // Since the edges are unweighted, BFS is more appropriate than Dijkstra's algorithm.
        // multi-source BFS starting with all the buses that have the source
        // keeping track of visited routes not stops for efficiency

/*
        // Bus Stops as Nodes
        //O(routes.size()^2 * max(routes[i].size()));

        //base case
        if(source==target) return 0;

        unordered_map<int, vector<int>> adjList;
        for(int i=0;i<routes.size();i++){
            for(auto &route: routes[i]){
                adjList[route].push_back(i);
            }
        }

        queue<int> q;
        set<int> visitedSt;
        for(auto &route : adjList[source]){
            q.push(route); //multisource BFS
            visitedSt.insert(route);
        }

        int bus=1;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++) {
                int top = q.front();
                q.pop();

                for(auto& route: routes[top]){
                    if(route==target) return bus;

                    //iterate the next route also
                    for(auto &nextNode: adjList[route]){
                        if(!visitedSt.count(nextNode)){
                            visitedSt.insert(nextNode);
                            q.push(nextNode);
                        }
                    }
                }
            }
            bus++;
        }
        return -1;
*/

        //  Routes as Nodes
        // Same time complexity with efficient memory complexity
        // multi-source BFS

        int n = routes.size();
        if (source == target) {
            return 0;
        }
        
        for (int i = 0; i < routes.size(); ++i) {
            sort(routes[i].begin(), routes[i].end());
        }
        
        createGraph(routes);

        queue<int> q;
        addStartingNodes(q, routes, source);
        
        vector<int> vis(n, 0);
        int busCount = 1;
         while (!q.empty()) {
            int sz = q.size();
            
            while (sz--) {
                int node = q.front();
                q.pop();
                
                // Return busCount, if the stop target is present in the current route.
                if (isStopExist(routes[node], target)) {
                    return busCount;
                }
                
                // Add the adjacent routes.
                for (int adj : adjList[node]) {
                    if (!vis[adj]) {
                        vis[adj] = 1;
                        q.push(adj);
                    }
                }
            }
            
            busCount++;
        }
        return -1;
    }

private:
        vector<int> adjList[501];

        // Iterate over each pair of routes and add an edge between them if there's a common stop.
        void createGraph(vector<vector<int>>& routes) {
            for (int i = 0; i < routes.size(); i++) {
                for (int j = i + 1; j < routes.size(); j++) {
                    if (haveCommonNode(routes[i], routes[j])) {
                        adjList[i].push_back(j);
                        adjList[j].push_back(i);
                    }
                }
            }
        }
        
        // Returns true if the provided routes have a common stop, false otherwise.
        bool haveCommonNode(vector<int>& route1, vector<int>& route2) {
            int i = 0, j = 0;
            while (i < route1.size() && j < route2.size()) {
                if (route1[i] == route2[j]) {
                    return true;
                }
                
                route1[i] < route2[j] ? i++ : j++;
            }
            return false;
        }

         // Add all the routes in the queue that have the source as one of the stops.
        void addStartingNodes(queue<int>& q, vector<vector<int>>& routes, int source) {
            for (int i = 0; i < routes.size(); i++) {
                if (isStopExist(routes[i], source)) {
                    q.push(i);
                }
            }
        }

        // Returns true if the given stop is present in the route, false otherwise.
        bool isStopExist(vector<int>& route, int stop) {
            for (int j = 0; j < route.size(); j++) {
                if (route[j] == stop) {
                    return true;
                }
            }
            return false;
        }
};