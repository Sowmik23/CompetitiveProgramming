// 1416. Restore The Array
class Solution {
public:
    const int mod = 1e9+7;
    int numberOfArrays(string s, int k) {
        
        int n = s.size();
        vector<int> dp(n+1, -1);

        return recursive(dp, s, k, 0);
    }
private:
    int recursive(vector<int> &dp, string &s, int k, int idx){
        
        if(idx==s.size()) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];

        int cnt = 0;
        long num = 0;
        for(int i=idx;i<s.size();i++){
            num = num*10 + s[i]-'0';
            if(num>k) break;
            cnt = (cnt+recursive(dp, s, k, i+1))%mod;
        }
        return dp[idx] = cnt;
    }
};