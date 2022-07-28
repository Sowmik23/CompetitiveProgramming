class Solution {
public:
    int countAsterisks(string s) {
        
        int cnt = 0;
        int p = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='|') p++;
            if(p%2==0 and s[i]=='*') cnt++;
        }
        
        return cnt;
    }
};
