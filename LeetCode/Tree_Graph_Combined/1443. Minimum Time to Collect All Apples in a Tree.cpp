class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        vector<int> graph[n];
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(graph, hasApple, 0, -1);
    }
private:
    int dfs(vector<int> graph[], vector<bool> &hasApple, int root, int prev){
        int distance = 0;

        for(auto i: graph[root]){
            if(i!=prev){
                int tmp = dfs(graph, hasApple, i, root);
                if(hasApple[i]) {
                    distance+=(2+tmp);
                    hasApple[root]=true; //hasApple[node] has been changed to true because its child has an apple, so for sure you will be returning back.
                }
            }
        }
        return distance;
    }
};
