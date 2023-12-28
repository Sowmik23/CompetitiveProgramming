class UnionFind {
    private:
        int totalComponents;
        vector<int> parent, rank;
    public:
        UnionFind(int n){
            totalComponents = n;
            parent = vector<int> (n);
            rank = vector<int> (n, 0);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }

        void Union(int x, int y){
            int a = Find(x);
            int b = Find(y);

            if(a==b) return ;
            if(rank[a]<rank[b]){
                parent[a] = b;
            }
            else if(rank[a]>rank[b]){
                parent[b] = a;
            }
            else {
                parent[b] = a;
                rank[a]++;
            }
            totalComponents--;
        }
        int Find(int x){
            if(x!=parent[x])  parent[x] = Find(parent[x]);
            return parent[x];
        }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {

        int n = vals.size();
        vector<vector<int>> graph(n);

        for(auto& e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[vals[i]].push_back(i);
        }

        UnionFind *uf = new UnionFind(n);
        int numOfGoodPaths = 0;

        for(auto& [values, nodes]: mp){
            for(auto& node: nodes){
                for(auto& neighbour: graph[node]){
                    if(vals[node]>=vals[neighbour]){
                        uf->Union(node, neighbour);
                    }
                }
            }

            unordered_map<int, int> group;
            for(auto& node: nodes){
                group[uf->Find(node)]++;
            }
            for(auto& [_, size]: group){
                numOfGoodPaths+= (size*(size+1)/2);
            }
        }
        return numOfGoodPaths;
    }
};
