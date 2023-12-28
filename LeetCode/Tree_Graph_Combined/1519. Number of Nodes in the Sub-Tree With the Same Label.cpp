class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<int> res(n, 0);
        vector<vector<int>> graph(n);

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(graph, labels, res, 0, -1);

        return res;
    }
private:
    vector<int> dfs(vector<vector<int>> &graph, string &labels, vector<int> &res, int root, int parent){

        vector<int> nodeCounts(26);
        nodeCounts[labels[root]-'a'] = 1;

        for(auto& child: graph[root]){
            if(parent==child) continue;
            vector<int> childCounts = dfs(graph, labels, res, child, root);
            for(int i=0;i<26;i++){
                nodeCounts[i]+=childCounts[i];
            }
        }
        res[root] = nodeCounts[labels[root]-'a'];
        return nodeCounts;
    }
};
