// 839. Similar String Groups
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        
        //dfs
        /*
        int n = strs.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimillar(strs[i], strs[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs_visit(graph, visited, i);
                cnt++;
            }
        }
        return cnt;
        */

        // union find
        int n = strs.size();
        UnionFind *uf = new UnionFind(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimillar(strs[i], strs[j])){
                    uf->Union(i, j);
                }
            }
        }
        return uf->getComponents();
    }
private:
    bool isSimillar(string str1, string str2){
        int diff = 0;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]) diff++;
        }
        return diff==0 or diff==2;
    }
    void dfs_visit(vector<vector<int>> &graph, vector<bool> &visited, int node){
        visited[node] = true;
        for(auto& neighbour: graph[node]){
            if(!visited[neighbour]){
                dfs_visit(graph, visited, neighbour);
            }
        }
    }
    class UnionFind {
        private:
            vector<int> parent, rank;
            int components;
        public:
            UnionFind(int n){
                components = n;
                parent = vector<int> (n);
                rank = vector<int> (n, 0);
                for(int i=0;i<n;i++){
                    parent[i] = i;
                }
            }
            int find(int x){
                if(parent[x]!=x) parent[x] = find(parent[x]);
                return parent[x];
            }
            void Union(int x, int y){
                int a = find(x);
                int b = find(y);
                if(a==b) return;
                if(rank[a]<rank[b]){
                    parent[a] = parent[b];
                }
                else if(rank[a]>rank[b]){
                    parent[b] = parent[a];
                }
                else {
                    parent[b] = parent[a];
                    rank[a]++;
                }
                components--;
            }
            int getComponents() {
                return this->components;
            }
    };
};