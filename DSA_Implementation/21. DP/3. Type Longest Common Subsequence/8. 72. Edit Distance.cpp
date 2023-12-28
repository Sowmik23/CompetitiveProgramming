class Solution {
public:
    int minDistance(string word1, string word2) {

        //recursive
        // return recursive(word1, word2, word1.size(), word2.size());

        //recursion with memoization
        // vector<vector<int>> memo(word1.size()+1, vector<int> (word2.size()+1, -1));
        // return recursionWithMemo(word1, word2, memo, word1.size(), word2.size());

        //tabulation
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1, 0));

        //base case: if i==0 return j and if j==0 return i;
        for(int i=0;i<=word2.size();i++) dp[0][i] = i;
        for(int i=0;i<=word1.size();i++) dp[i][0] = i;

        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min({1+dp[i-1][j], 1+dp[i][j-1], 1+dp[i-1][j-1]});
            }
        }
        return dp[word1.size()][word2.size()];
    }
private:
    int recursive(string word1, string word2, int i, int j){
        if(i==0) return j;
        if(j==0) return i;

        if(word1[i-1]==word2[j-1]) return recursive(word1, word2, i-1, j-1);
        return min({1+recursive(word1, word2, i-1, j), 1+recursive(word1, word2, i, j-1), 1+recursive(word1, word2, i-1, j-1)});
    }
    int recursionWithMemo(string str1, string str2, vector<vector<int>> &memo, int i, int j){
        if(i==0) return j;
        if(j==0) return i;

        if(memo[i][j]!=-1) return memo[i][j];
        if(str1[i-1]==str2[j-1]) return recursionWithMemo(str1, str2, memo, i-1, j-1);
        return memo[i][j] = min({1+recursionWithMemo(str1, str2, memo, i-1, j), 1+recursionWithMemo(str1, str2, memo, i, j-1), 1+recursionWithMemo(str1, str2, memo, i-1, j-1)});
    }
};
