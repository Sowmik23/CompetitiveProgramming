// 1759. Count Number of Homogenous Substrings

class Solution {
public:
    int countHomogenous(string s) {
        
        //number of all possible substring of length 1 to n
        // (n^2 + n)/2

        const int mod = 1e9+7;

        int res = 0;
        int n = s.size();
        int cnt = 1;

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) cnt++;
            else {
                long sameTypeCnt = ((long)((long)cnt*cnt)%mod + cnt)/2;
                res+=sameTypeCnt%mod;
                cnt = 1;
            }
        }
        long sameTypeCnt = (((long)((long)cnt*cnt)%mod + cnt)%mod)/2;
        res+=sameTypeCnt%mod;

        return res;
    }
};