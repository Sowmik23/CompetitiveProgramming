class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> cnt(n, 0);
        
        for(int i=0;i<edges.size();i++){
            cnt[edges[i][1]]++;
        }
        
        vector<int> res;
        for(int i=0;i<n;i++){
            if(cnt[i]==0) res.push_back(i);
        }
        
        
        return res;
    }
};
