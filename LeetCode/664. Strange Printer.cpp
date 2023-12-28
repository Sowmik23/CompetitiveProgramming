// 664. Strange Printer

class Solution {
public:
    int strangePrinter(string s) {

        //Dynamic programming
        //Time: O(n^3)

        int n = s.size();

        //recursive: TLE
        // return recursive(s, 0, n-1)+1;   

        //recursion with memoization: TLE
        // vector<vector<int>> memo(n, vector<int> (n, -1));
        // return recursionWithMemo(s, 0, n-1, memo)+1;

   /*     //Tabulation: O(n^3)
        // vector<vector<int>> dp(n, vector<int>(n));
        // for(int len=1;len<=n;len++){
        //     for(int left = 0;left<=n-len;left++){
        //         int right = len+left-1;
        //         int k = -1;
        //         for(int i=left;i<right;i++){
        //             if(s[i]!=s[right] and k==-1){
        //                 k = i;
        //             }
        //             if(k!=-1) {
        //                 dp[left][right] = min(dp[left][right], 1+dp[k][i]+dp[i+1][right]);
        //             }
        //         }
        //         if(k==-1) dp[left][right] = 0;
        //     }
        // }

        vector dp(n, vector<int>(n, n));
         for (int length = 1; length <= n; length++) {
            for (int left = 0; left <= n - length; left++) {
                int right = left + length - 1;
                int j = -1;
                for (int i = left; i < right; i++) {
                    if (s[i] != s[right] && j == -1) {
                        j = i;
                    }
                    if (j != -1) {
                        dp[left][right] = min(dp[left][right], 1 + dp[j][i] + dp[i + 1][right]);
                    }
                }
                
                if (j == -1) {
                    dp[left][right] = 0;
                }
            }
        }

        return dp[0][n-1]+1;
*/


        // O(N3)
        vector<vector<int>> dp(n, vector<int>(n,0));
        // dp[i][j]: Minimal turns to print s[i] to s[j] 
        return helper(s, 0, n-1, dp);
    }
private:
    int helper(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i>j) return 0;
        if (dp[i][j]) return dp[i][j];
        int res = helper(s, i, j-1, dp) + 1;
        for (int k=i;k<j;k++) {
            if (s[k] == s[j]) {
                res = min(res, helper(s, i, k, dp) + helper(s, k+1, j-1, dp));
            }
        }
        return dp[i][j] = res;
    }
    int recursive(string s, int left, int right){

        int k = -1;
        int res = INT_MAX;

        for(int i=left;i<right;i++){
            if(s[i]!=s[right] and k==-1){
                k = i;
            }
            if(k!=-1){
                res = min(res, 1+recursive(s, k, i)+recursive(s, i+1, right));
            }
        }
        if(k==-1) res = 0;
        return res;
    }
    int recursionWithMemo(string s, int left, int right, vector<vector<int>> &memo){
        if(memo[left][right]!=-1) return memo[left][right];

        memo[left][right] = s.size(); //init with max value
        int k = -1;
        for(int i=left;i<right;i++){
            if(s[i]!=s[right] and k==-1) k = i;
            if(k!=-1){
                memo[left][right] = min(memo[left][right], 1+recursionWithMemo(s, k, i, memo)+recursionWithMemo(s, i+1, right, memo));
            }
        }
        if(k==-1) memo[left][right] = 0;
        return memo[left][right];
    }
};