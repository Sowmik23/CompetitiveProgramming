// 1697. Checking Existence of Edge Length Limited Paths
class UnionFind {
private:
    vector<int> rank, parent;
    int components;

public:
    UnionFind(int n){
        this->components = n;
        rank = vector<int> (n,0);
        parent = vector<int> (n);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int find(int x){
        if(x!=parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y){
        int g1 = find(x);
        int g2 = find(y);
        if(g1==g2) return;
        if(rank[g1]<rank[g2]){
            parent[g1] = parent[g2];
        }
        else if(rank[g1]>rank[g2]){
            parent[g2] = parent[g1];
        }
        else {
            parent[g1] = parent[g2];
            rank[g2]++;
        }
    }
    bool areConnected(int x, int y){
        int g1 = find(x);
        int g2 = find(y);
        return g1==g2;
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        int m = queries.size();
        vector<bool> res(m);

        vector<vector<int>> queriesTmp(m);
        for(int i=0;i<m;i++){
            queriesTmp[i] = queries[i];
            queriesTmp[i].push_back(i);
        }

        //sort edgelist with increasing order of weights
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b){
            return a[2]<b[2];
        });

        //sort queriesTmp with increasing order of limit weight
        sort(queriesTmp.begin(), queriesTmp.end(), [](auto& a, auto& b){
            return a[2]<b[2];
        });

        UnionFind *uf = new UnionFind(n);
        int i = 0;

        //iterate each query
        for(auto& query: queriesTmp){
            int src = query[0];
            int dest = query[1];
            int limit = query[2];
            int idx = query[3];

            while(i<edgeList.size() and edgeList[i][2]<limit){
                int u = edgeList[i][0];
                int v = edgeList[i][1];
                uf->Union(u, v);
                i++;
            }
            //if src and dest both are same component then they are recheable from each other
            res[idx] = uf->areConnected(src, dest);
        }
        return res;
    }
};
