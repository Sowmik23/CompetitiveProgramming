class DSU {
    private:
        vector<int> parent, rank;
        int numComponents;
    public:
        DSU(int n){
            numComponents = n;
            parent = vector<int> (n);
            rank = vector<int> (n);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        void Union(int a,  int b){
            int x = find(a);
            int y = find(b);

            if(x==y) return ; //already in the same set
            if(rank[x]<rank[y]){ //put smaller ranked item on bigger rank item
                parent[x] = y;
            }
            else if(rank[x]>rank[y]){
                parent[y] = x;
            }
            else {
                parent[y] = x;
                rank[x]++;
            }
            numComponents--;
        }
        int find(int a){
            if(a!=parent[a]) parent[a] = find(parent[a]);
            return parent[a];
        }
        bool isConnected(int a, int b){
            return find(a)==find(b);
        }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        //try with union find/DSU

        DSU *dsu = new DSU(n);
        for(int i=0;i<edges.size();i++){
            dsu->Union(edges[i][0], edges[i][1]);
        }
        return dsu->isConnected(source,  destination);
    }
};
