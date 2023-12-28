// 1763. Longest Nice Substring
class Solution {
public:
    string longestNiceSubstring(string s) {
        
        if(s.size()<2) return "";

        unordered_map<int, int> mp;
        for(auto& ch: s){
            if(ch>='a' and ch<='z') mp[ch-'a']++;
            else mp[ch-'A'+26]++;
        }

        for(int i=0;i<s.size();i++){
            if(mp.find(toupper(s[i])-'A'+26)!=mp.end() and mp.find(tolower(s[i])-'a')!=mp.end()) continue;
            else {
                string prefix = longestNiceSubstring(s.substr(0, i));
                string suffix = longestNiceSubstring(s.substr(i+1));
                return prefix.size()>=suffix.size() ? prefix : suffix;
            }
        }
        return s;
    }
};