class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {

        unordered_map<int, int> mp;
        for(auto item: items1){
            mp[item[0]] +=item[1];
        }
        for(auto& item: items2){
            mp[item[0]] +=item[1];
        }

        vector<vector<int>> res;
        for(auto& m: mp){
            res.push_back({m.first, m.second});
        }

        sort(res.begin(), res.end(), [](auto& a, auto& b){
            return a[0]<b[0];
        });

        return res;
    }
};
