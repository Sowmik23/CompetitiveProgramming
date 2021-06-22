class Solution {
public:
    int countGoodSubstrings(string s) {
        
        
        unordered_map<char, int> mp;
        int answer=0;
        
        for (int i = 0; i < 3; i++) {
            mp[s[i]]++;
        }
 
        if (mp.size() ==3) answer++;
 
    
        for (int i = 3; i < s.size(); i++) {
            mp[s[i]]++;

            mp[s[i - 3]]--;


            if (mp[s[i - 3]] == 0) {
                mp.erase(s[i - 3]);
            }


            if (mp.size() == 3) {
                answer++;
            }
        }
        return answer;
    }
};
