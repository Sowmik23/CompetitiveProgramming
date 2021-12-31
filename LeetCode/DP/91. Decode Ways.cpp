class Solution {
public:
    int numDecodings(string s) {
        
        if(s.size()==0) return 0;
        vector<int> memo(s.size()+1, -1);
        
        return dp(s, memo, 0);
    }
private:
    int dp(string &s, vector<int> &memo, int i){
        
        if(i>s.size()) return 0;
        if(s[i]=='0') return 0;
        
        if(i==s.size()) return 1;
        if(memo[i]!=-1) return memo[i];
        
        int res = dp(s, memo, i+1);
        memo[i] = res;
        
        if(i+1<s.size() and (s[i]=='1' or (s[i]=='2' and s[i+1]<'7'))) res+=dp(s, memo, i+2);
        memo[i] = res;
        return res;
    }
};
