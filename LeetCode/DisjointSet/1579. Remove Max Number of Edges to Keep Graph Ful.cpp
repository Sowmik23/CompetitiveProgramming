// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// class UnionFind {
// private:
//     vector<int> rank, parent;
//     vector<int> componentSize;
//     int components;
// public:
//     UnionFind(int n){
//         components = n;
//         rank = vector<int> (n+9, 0);
//         parent = vector<int> (n+9);
//         for(int i=0;i<=n;i++) {
//             parent[i] = i;
//             componentSize.push_back(1);
//         }
//     }
//     int find(int x){
//         if(x!=parent[x]) parent[x] = find(parent[x]);
//         return parent[x];
//     }
//     int Union(int x, int y){
//         int g1 = find(x);
//         int g2 = find(y);
//         if(g1==g2) return 0;
//         // if(rank[g1]<rank[g2]){
//         //     parent[g1] = parent[g2];
//         // }
//         // else if(rank[g1]>rank[g2]){
//         //     parent[g2] = parent[g1];
//         // }
//         // else {
//         //     parent[g1] = parent[g2];
//         //     rank[g2]++;
//         // }

//         if(componentSize[g1]>componentSize[g2]){
//             componentSize[x]+=componentSize[g2];
//             parent[g2] = g1;
//         }
//         else {
//             componentSize[g2]+=componentSize[g1];
//             parent[g1] = g2;
//         }
//         components--;
//         return 1;
//     }
//     bool areSameComponent(int x, int y){
//         int g1 = find(x);
//         int g2 = find(y);
//         return g1==g2;
//     }
//     int getComponent(){
//         return components;
//     }
//     bool isConnected() {
//         return components==1;
//     }
// };

// class Solution {
// public:
//     int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
//         int usedEdge = 0;

//         UnionFind alice(n), bob(n);

//         for(auto& edge: edges){
//             int type = edge[0];
//             int u = edge[1];
//             int v = edge[2];
//             if(type==3){
//                 usedEdge+= (alice.Union(u, v) | bob.Union(u, v));
//             }
//         }
//         for(auto& edge: edges){
//             int type = edge[0];
//             int u = edge[1];
//             int v = edge[2];
//             if(type==1) usedEdge+=alice.Union(u, v);
//             else if(type==2) usedEdge+=bob.Union(u, v);
//         }
//         cout<<alice.getComponent()<<" "<<bob.getComponent()<<endl;
//         cout<<alice.isConnected()<<" "<<bob.isConnected()<<endl;

//         if(alice.getComponent()==1 and bob.getComponent()==1){
//             return edges.size()-usedEdge;
//         }
//         return -1;
//     }
// };


class UnionFind {
    vector<int> representative;
    vector<int> componentSize;
    int components;
    
public:
    UnionFind(int n) {
        components = n;
        for (int i = 0; i <= n; i++) {
            representative.push_back(i);
            componentSize.push_back(1);
        }
    }
    
    int findRepresentative(int x) {
        if (representative[x] == x) {
            return x;
        }
        return representative[x] = findRepresentative(representative[x]);
    }
    
    int performUnion(int x, int y) {       
        x = findRepresentative(x); 
        y = findRepresentative(y);
        if (x == y) return 0;
        if (componentSize[x] > componentSize[y]) {
            componentSize[x] += componentSize[y];
            representative[y] = x;
        } else {
            componentSize[y] += componentSize[x];
            representative[x] = y;
        }
        
        components--;
        return 1;
    }
    
    bool isConnected() {
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        UnionFind Alice(n), Bob(n);

        int edgesRequired = 0;
        
        for (vector<int>& edge : edges) {
            if (edge[0] == 3) {
                edgesRequired += (Alice.performUnion(edge[1], edge[2]) | Bob.performUnion(edge[1], edge[2]));
            }
        }

        for (vector<int>& edge : edges) {
            if (edge[0] == 1) {
                edgesRequired += Alice.performUnion(edge[1], edge[2]);
            } else if (edge[0] == 2) {
                edgesRequired += Bob.performUnion(edge[1], edge[2]);
            }
        }

        if (Alice.isConnected() && Bob.isConnected()) {
            return edges.size() - edgesRequired;
        }
        
        return -1;
    }
};