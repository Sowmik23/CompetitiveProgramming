class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        map<int, int> mp;
        
        for(auto& t: trips){
            mp[t[1]]+=t[0];
            mp[t[2]]-=t[0];
        }
        
        for(auto& m: mp){
            capacity = capacity-m.second;
            if(capacity<0) return false;
        }
        
        return true;
    }
};
