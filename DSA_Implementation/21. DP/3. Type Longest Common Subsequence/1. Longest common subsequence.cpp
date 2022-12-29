class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        //recursion: TLE
        return recursive(text1,  text2, text1.size(), text2.size());

        //recursion with memoization: TLE
        vector<vector<int>> memo(text1.size(), vector<int> (text2.size(), -1));
        return recursionWithMemo(text1, text2, memo, text1.size(), text2.size());

        //tabulation: Accepted
        // Time: O(m*n)
        // Space: O(m*n)
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];

        //tabulation with optimized memory
        //Time: O(m*n)
        //Space: O(n)
        vector<vector<int>> dp(2, vector<int> (text2.size()+1, 0));
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1])  dp[i&1][j] = 1 +dp[i&1^1][j-1];
                else dp[i&1][j] = max(dp[i&1^1][j], dp[i&1][j-1]);
            }
        }
        return dp[text1.size()&1][text2.size()];
    }
private:
  //Time: O(m*n)
  //Space:
    int recursive(string text1, string text2, int i, int j){

        if(i==0 or j==0) return 0;

        if(text1[i-1]==text2[j-1]){
            return 1+recursive(text1, text2, i-1, j-1);
        }
        return max(recursive(text1, text2, i-1, j), recursive(text1, text2, i, j-1));
    }

    //Time: O(m*n)
    //Space: O(m*n)
    int recursionWithMemo(string text1, string text2, vector<vector<int>> &memo, int i, int j){
        if(i==0 or j==0) return 0;
        if(memo[i-1][j-1]!=-1) return memo[i-1][j-1];
        if(text1[i-1]==text2[j-1]){
            return memo[i-1][j-1]  = 1+recursionWithMemo(text1, text2, memo, i-1, j-1);
        }
        return memo[i-1][j-1] = max(recursionWithMemo(text1, text2, memo, i-1, j), recursionWithMemo(text1, text2, memo, i, j-1));
    }
};
