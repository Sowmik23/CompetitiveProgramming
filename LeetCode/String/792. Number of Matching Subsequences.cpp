class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       
        
        map<string, bool> mp;
        int cnt = 0;
        
        for(int i=0;i<words.size();i++){
            if(mp.find(words[i])!=mp.end()){
                if(mp[words[i]]==true){
                    cnt++;
                }
                continue;
            }
            
            mp[words[i]] = isSubsequenceIterative(s, words[i], s.size(), words[i].size());
            if(mp[words[i]]==true) cnt++;
        }

        
        return cnt;
    }
private:
    //TLE
//     bool isSubsequence(string str, string s, int i, int j){
        
//         if(j==0) return true;
//         if(i==0) return false;
             

//         if(str[i-1]==s[j-1])  return isSubsequence(str, s, i-1, j-1);
//         return isSubsequence(str, s, i-1, j);
//     }
    bool isSubsequenceIterative(string s1, string s2, int m, int n){
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
            if(s1[i] == s2[j]) j++;
        }
        return j == n;
    }
};
