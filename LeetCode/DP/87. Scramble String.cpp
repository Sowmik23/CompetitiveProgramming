// 87. Scramble String
class Solution {
public:
    bool isScramble(string s1, string s2) {
        
        //DP
        // Time: O(n^4)

        return solve(s1, s2);
    }
private:
    unordered_map<string, bool> mp;
    bool solve(string s1, string s2){
        if(s1==s2) return true;
        if(s1.length()!=s2.length()) return false;

        string key = s1+"_"+s2;
        if(mp.find(key)!=mp.end()) return mp[key];

        bool res = false;
        int n = s1.size();
        for(int i=1;i<n;i++){
            bool isSwapped = solve(s1.substr(0, i), s2.substr(n-i, i)) && solve(s1.substr(i, n-i), s2.substr(0, n-i));
            if(isSwapped) {
                res = true;
                break;
            }

            bool isNotSwapped = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n-i), s2.substr(i, n-i));
            if(isNotSwapped) {
                res = true;
                break;
            }
        }
        return mp[key] = res;
    }
};