class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> mp;
        unordered_set<int> st;
        
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end() and mp[s[i]]!=t[i]) return false;
            if(mp.find(s[i])==mp.end() and st.count(t[i])!=0) return false;
            
           mp[s[i]] = t[i];
           st.insert(t[i]);
        }
        
        return true;
    }
};
