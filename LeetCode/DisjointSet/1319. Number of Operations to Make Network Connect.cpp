// 1319. Number of Operations to Make Network Connected

class UnionFind {
public:
    vector<int> rank, parent;
    int numOfComponents;

    UnionFind(int n){
        numOfComponents = n;
        rank = vector<int> (n, 0);
        parent = vector<int> (n);
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int find(int x){
        if(parent[x]!=x) x = find(parent[x]);
        return x;
    }
    void Union(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x==y) return;
        if(rank[x]<rank[y]){
            parent[y] = x;
        }
        else if(rank[x]>rank[y]){
            parent[x] = y;
        }
        else {
            parent[y] = x;
            rank[x]--;
        }
        numOfComponents--;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        //using Disjoin Set 
        /*
        UnionFind* uf = new UnionFind(n);
        if(connections.size()<n-1) return -1; //impossible to connect all the network

        for(auto& conn: connections){
           uf->Union(conn[0], conn[1]);
        }

        return uf->numOfComponents-1;
        */

        //using DFS
        if(connections.size()<n-1) return -1;
        vector<vector<int>> graph(n);
        for(auto& conn: connections){
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        vector<bool> visited(n, false);
        int numOfComponents = 0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs_visit(i, graph, visited);
                numOfComponents++;
            }
        }
        return numOfComponents-1;

        //BFS is same as dfs
    }
private:
    void dfs_visit(int u, vector<vector<int>> &graph, vector<bool> &visited){
        visited[u] = true;
        vector<int> ::iterator it;
        for(it=graph[u].begin();it!=graph[u].end();it++){
            if(!visited[*it]) dfs_visit(*it, graph, visited);
        }    
    }
};