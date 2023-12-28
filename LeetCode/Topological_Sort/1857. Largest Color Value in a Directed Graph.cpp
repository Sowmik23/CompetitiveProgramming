// 1857. Largest Color Value in a Directed Graph
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n);

        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        int totalVisitedNode = 0;
        int res = -1;
        vector<vector<int>> mp(n, vector<int> (26));

        while(!q.empty()){
            int top = q.front();
            q.pop();
            mp[top][colors[top]-'a']++;
            res = max(res, mp[top][colors[top]-'a']);
            totalVisitedNode++;

            for(auto& node: graph[top]){
                for(int i=0;i<26;i++){
                    mp[node][i] = max(mp[node][i], mp[top][i]);
                }
                indegree[node]--;
                if(indegree[node]==0) q.push(node);
            }
        }

        if(totalVisitedNode<n) return -1;
        return res;
    }
};