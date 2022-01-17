class Solution {
public:
    string smallestSubsequence(string s) {
        
        string res = "";
        
        int last[26] = {};
        int seen[26] = {};
        
        for(int i=0;i<s.size();i++){
            last[s[i]-'a'] = i;
        }
        
        for(int i=0;i<s.size();i++){
            
            seen[s[i]-'a']++;
            if(seen[s[i]-'a'] > 1){
                continue;
            }
            
            while(!res.empty() and res.back()>s[i] and i<last[res.back()-'a']){
                seen[res.back()-'a'] = 0;
                res.pop_back();
            }
            
            res.push_back(s[i]);
        }
        
        
        return res;
    }
};
