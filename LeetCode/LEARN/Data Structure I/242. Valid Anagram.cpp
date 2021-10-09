class Solution {
public:
    bool isAnagram(string s, string t) {
       
        //Approach-01: sorting
        /*
        if(s.size()!=t.size()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]) return false;
        }
        
        return true;
        */
        
        //Approach-02: freq counting
        
        if(s.size()!=t.size()) return false;
        vector<int> freq(26, 0);
        
        for(auto& ch : s){
            freq[ch-'a']++;
        }
        
        for(auto& ch: t){
            if(freq[ch-'a']<1) return false;
            freq[ch-'a']--;
        }
        
        return true;
    }
};
