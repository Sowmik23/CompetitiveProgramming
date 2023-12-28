// 1400. Construct K Palindrome Strings
class Solution {
public:
    bool canConstruct(string s, int k) {
        
        //condition ot have k palindrome string
        // odd count <=k and k<=s.size()

        unordered_map<int, int> mp;
        for(auto& ch : s) mp[ch-'a']++;
        
        int oddFreq = 0;
        for(auto& m: mp) if(m.second&1) oddFreq++;

        return oddFreq<=k and k<=s.size();
    }
};