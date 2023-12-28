class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, int> mp_s, mp_t;

        //though s and t are same length here for this problem . But if not
        if(s.size()!=t.size()) return false;

        for(int i=0;i<s.size();i++){
            if(mp_s.find(s[i])!=mp_s.end() and mp_t.find(t[i])!=mp_t.end()){
                if(mp_s[s[i]]!=mp_t[t[i]]) return false;
            }
            else if((mp_s.find(s[i])!=mp_s.end() and mp_t.find(t[i])==mp_t.end()) or (mp_s.find(s[i])==mp_s.end() and mp_t.find(t[i])!=mp_t.end())) return false;
            mp_s[s[i]] = mp_t[t[i]] = i+1;
        }

        return true;
    }
};



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
