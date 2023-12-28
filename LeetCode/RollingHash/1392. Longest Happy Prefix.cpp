// 1392. Longest Happy Prefix
class Solution {
public:
    string longestPrefix(string s) {
        
        //Rolling hash
        long h1 = 0, h2 = 0, mul = 1;
        long mod = 1e8+7;
        long mxLen = 0;

        for(int i = 0, j = s.size()-1;j>0;i++,j--){
            int first = s[i]-'a';
            int last = s[j]-'a';
            
            h1 = (h1*26 + first)%mod;
            h2 = (h2 + last*mul)%mod;
            mul = (mul*26)%mod;
            
            if(h1==h2) mxLen = i+1;
        }
        return s.substr(0, mxLen);
    }
};