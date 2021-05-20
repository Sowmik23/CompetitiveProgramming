class Solution {
public:
    bool isAnagram(string s, string t) {
      
        ///approach-01: Time: nlogn, Memory: o(n)
        /*sort(s.begin(), s.end());
        // cout<<s<<endl;
        
        sort(t.begin(), t.end());
        // cout<<t<<endl;
        if(s.size()==t.size() and s==t.substr(0, s.size())) return true;
        return false; */
        
        if(s.size()!=t.size()) return false;
        map<char, int> mp, mp1;
        for(char i: s) mp[i]++;
        
        for(char i: t) mp1[i]++;
        
        
        for(char i: s){
            if(mp[i]!=mp1[i]) return false;
        }
        return true;
    }
};
