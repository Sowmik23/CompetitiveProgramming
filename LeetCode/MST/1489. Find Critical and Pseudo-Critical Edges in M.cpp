// 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
class Solution {
    class UnionFind {
        public:
            vector<int> parent, size;
            int mxSize;
            UnionFind(int n){
                this->mxSize = 1;
                size.resize(n, 1);
                parent.resize(n);
                for(int i=0;i<n;i++){
                    parent[i] = i;
                }
            }
            int find(int x){
                if(parent[x]!=x) return find(parent[x]);
                return parent[x];
            }
            bool Union(int x, int y){
                int rootX = find(x);
                int rootY = find(y);
                if(rootX!=rootY){
                    if(size[rootX]<size[rootY]){
                        swap(rootX, rootY);
                    }
                    parent[rootY] = rootX;
                    size[rootX]+=size[rootY];
                    mxSize = max(mxSize, size[rootX]);
                    return true;
                }
                return false;
            }
    };
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        auto newEdges = edges;

        //add index to edges for tracking
        for(int i=0;i<m;i++){
            newEdges[i].push_back(i);
        }

        //sort edges based on edge weight
        sort(newEdges.begin(), newEdges.end(), [](auto& a, auto& b){
            return a[2]<b[2];
        });

        //find MST weight using union-find
        UnionFind *uf = new UnionFind(n);
        int wt = 0;
        for(auto& edge: newEdges){
            if(uf->Union(edge[0], edge[1])){
                wt+=edge[2];
            }
        }

        vector<vector<int>> res(2);//critical and psedu-critical
        for(int i=0;i<m;i++){
            UnionFind uf2(n);
            int ignorWt = 0;
            for(int j=0;j<m;j++){
                if(i!=j and uf2.Union(newEdges[j][0], newEdges[j][1])){
                    ignorWt+=newEdges[j][2];
                }
            }

            //if the graph is disconnected or the total weight is greater
            //the edge is critical
            if(uf2.mxSize<n or ignorWt>wt){
                res[0].push_back(newEdges[i][3]);
            }
            else {
                //force this edge and calculate MST weight
                UnionFind uf3(n);
                uf3.Union(newEdges[i][0], newEdges[i][1]);
                int forceWt = newEdges[i][2];
                for(int j=0;j<m;j++){
                    if(i!=j and uf3.Union(newEdges[j][0], newEdges[j][1])){
                        forceWt+=newEdges[j][2];
                    }
                }

                //if total weight is the same, then it is pseudo-critical
                if(forceWt==wt){
                    res[1].push_back(newEdges[i][3]);
                }
            }
        }
        return res;
    }
};