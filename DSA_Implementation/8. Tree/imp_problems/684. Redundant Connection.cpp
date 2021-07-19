class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        ///union and find with path compression
        ///Time: O(n)
        ///Memory: O(n)
        
        
        parent.resize(edges.size()+1);
        
        //initialization
        for(int i=0;i<edges.size();i++){
            parent[i] = i;
        }
        
        for(auto e: edges){
            if(find(e[0])==find(e[1])) return e;
            else Union(e[0], e[1]);
        }
        
        return edges[0];
    }
    
private:
    vector<int> parent;
    
    int find(int x){
        if(x!=parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void Union(int x, int y){
        parent[find(y)] = find(x);
    }
};
