class Solution {
public:
    int longestPath(vector<int>& parent, string s) {

        vector<vector<int>> graph(parent.size());
        for(int i=1;i<parent.size();i++){
            graph[parent[i]].push_back(i);
        }
        int res = 0;
        dfs(graph, s, res, 0);
        return res;
    }
private:
    int dfs(vector<vector<int>> &graph, string &s, int &res, int node){

        int firstLargest = 0, secondLargest = 0;
        for(auto& child: graph[node]){
            int longestChainStartingFromChild = dfs(graph, s, res, child);
            if(s[child]==s[node]) continue;
            if(longestChainStartingFromChild>firstLargest){
                secondLargest = firstLargest;
                firstLargest = longestChainStartingFromChild;
            }
            else if(longestChainStartingFromChild>secondLargest){
                secondLargest = longestChainStartingFromChild;
            }
        }
        res = max(res, firstLargest+secondLargest+1);
        return firstLargest+1;
    }
};
