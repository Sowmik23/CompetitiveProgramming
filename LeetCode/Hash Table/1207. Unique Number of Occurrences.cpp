class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        map<int,  int> mp;
        for(auto& num: arr){
            mp[num]++;
        }

        set<int> st;
        for(auto& m: mp){
            if(st.find(m.second)!=st.end())return false;
            else st.insert(m.second);
        }
        return true;
    }
};
