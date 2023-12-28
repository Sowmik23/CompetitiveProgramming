// 1640. Check Array Formation Through Concatenation
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        vector<int> res;
        map<int, vector<int>> mp;
        for(auto& piece: pieces){
            mp[piece[0]] = piece;
        }
        for(auto& a: arr){
            if(mp.find(a)!=mp.end()){
                res.insert(res.end(), mp[a].begin(), mp[a].end());
            }
        }
        return res==arr;
    }
};