// 2050. Parallel Courses III

// class Solution {
// public:
//     unordered_map<int, vector<int>> graph;
    
//     int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) { 
//         unordered_map<int, vector<int>> graph;
//         vector<int> indegree = vector(n, 0);

//         for (vector<int>& edge: relations) {
//             int x = edge[0] - 1;
//             int y = edge[1] - 1;
//             graph[x].push_back(y);
//             indegree[y]++;
//         }
        
//         queue<int> queue;
//         vector<int> maxTime = vector(n, 0);
        
//         for (int node = 0; node < n; node++) {
//             if (indegree[node] == 0) {
//                 queue.push(node);
//                 maxTime[node] = time[node];
//             }
//         }
        
//         while (!queue.empty()) {
//             int node = queue.front();
//             queue.pop();
//             for (int neighbor: graph[node]) {
//                 maxTime[neighbor] = max(maxTime[neighbor], maxTime[node] + time[neighbor]);
//                 indegree[neighbor]--;
//                 if (indegree[neighbor] == 0) {
//                     queue.push(neighbor);
//                 }
//             }
//         }
        
//         int ans = 0;
//         for (int node = 0; node < n; node++) {
//             ans = max(ans, maxTime[node]);
//         }
        
//         return ans;
//     }
// };

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> memo;
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) { 
        for (vector<int>& edge: relations) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph[x].push_back(y);
        }
        
        memo = vector(n, -1);
        int ans = 0;
        for (int node = 0; node < n; node++) {
            ans = max(ans, dfs(node, time));
        }
        
        return ans;
    }
    
    int dfs(int node, vector<int>& time) {
        if (memo[node] != -1) {
            return memo[node];
        }
        
        if (graph[node].size() == 0) {
            return time[node];
        }
        
        int ans = 0;
        for (int neighbor: graph[node]) {
            ans = max(ans, dfs(neighbor, time));
        }
        
        memo[node] = time[node] + ans;
        return time[node] + ans;
    }
};