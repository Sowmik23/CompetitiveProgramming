class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        
        vector<int> res;
        res.push_back(first);
        for(auto i: encoded){
            int k = i^first;
            // cout<<k<<" ";
            res.push_back(k);
            first = k;
        }
        
        return res;
    }
};
