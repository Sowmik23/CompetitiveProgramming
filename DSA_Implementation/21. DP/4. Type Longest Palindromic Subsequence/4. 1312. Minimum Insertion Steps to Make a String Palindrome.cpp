class Solution {
public:
    int minInsertions(string s) {

        //top-down
        //recursive: TLE: 10/58
        // return recursive(s, 0, s.size()-1);

        //recursion with memoization: TLE: 48/58
        // vector<vector<int>> memo(s.size(), vector<int> (s.size(), -1));
        // return recursionWithMemo(s, memo, 0, s.size()-1);

        //tabulation(bottom up)
        vector<vector<int>> dp(s.size()+1, vector<int> (s.size()+1, 0));
        string s2 = s;
        reverse(s.begin(), s.end());

        //finding LCS for str and reverse of str
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++){
                if(s2[i-1]==s[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return s.size()-dp[s.size()][s.size()];
    }
private:
    int recursive(string str, int l, int r){
        if(l>=r) return 0;

        if(str[l]==str[r]) return recursive(str, l+1, r-1);
        return 1+min(recursive(str, l+1, r), recursive(str, l, r-1));
    }
    int recursionWithMemo(string str, vector<vector<int>> &memo, int l, int r){
        if(l>=r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];

        if(str[l]==str[r]) return recursionWithMemo(str, memo, l+1, r-1);
        return memo[l][r] = 1+min(recursionWithMemo(str, memo, l+1, r), recursionWithMemo(str, memo, l, r-1));
    }
};
