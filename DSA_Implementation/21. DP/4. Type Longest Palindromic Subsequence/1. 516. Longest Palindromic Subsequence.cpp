class Solution {
public:
    int longestPalindromeSubseq(string s) {


        //Solution:  LCS(original, reverse) :v

        string s1 = s;
        reverse(s.begin(), s.end());

        //recursive: TLE
        return recursive(s1, s, s.size(), s.size());

        //recursion with memoization: TLE
        vector<vector<int>> memo(s.size()+1, vector<int> (s.size()+1, -1));
        return recursionWithMemo(s1, s, memo, s.size(), s.size());

        //tabulation: Accepted
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];

        //tabulation with optimized memory
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s[j-1]) dp[i&1][j] = 1+dp[i&1^1][j-1];
                else dp[i&1][j] = max(dp[i&1^1][j], dp[i&1][j-1]);
            }
        }
        return dp[n&1][n];
    }
private:
    int recursive(string str1, string str2, int i, int j){
        if(i==0 or j==0) return 0;
        if(str1[i-1]==str2[j-1]) return 1+recursive(str1, str2, i-1, j-1);
        return max(recursive(str1, str2, i-1, j), recursive(str1, str2, i, j-1));
    }
    int recursionWithMemo(string str1, string str2, vector<vector<int>> &memo, int i, int j){
        if(i==0 or j==0) return 0;
        if(memo[i][j]!=-1) return memo[i][j];

        if(str1[i-1]==str2[j-1]) return memo[i][j] = 1+recursionWithMemo(str1, str2, memo, i-1, j-1);
        return memo[i][j] = max(recursionWithMemo(str1, str2, memo, i-1, j), recursionWithMemo(str1, str2, memo, i, j-1));
    }
};
