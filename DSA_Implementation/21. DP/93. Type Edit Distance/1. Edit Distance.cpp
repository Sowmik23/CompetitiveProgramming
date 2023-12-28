class Solution {
public:
    int minDistance(string word1, string word2) {
        
        
        
        //recursion with memoization
        vector<vector<int>> memo(word1.size()+1, vector<int> (word2.size()+1, -1));
        return dp(word1, word2, memo, 0, 0);

        //tabulation: TODO
        
    }
private:
    int dp(string &word1, string &word2, vector<vector<int>> &memo, int i, int j){
        if(i>=word1.size()) return memo[i][j] = word2.size()-j;
        if(j>=word2.size()) return memo[i][j] = word1.size()-i;
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        if(word1[i]==word2[j]) return memo[i][j] = dp(word1, word2, memo, i+1, j+1);
        else {
            return memo[i][j] = min(dp(word1, word2, memo, i+1, j)+1, min(dp(word1, word2, memo, i, j+1)+1, dp(word1, word2, memo, i+1, j+1)+1));
        }
    }
};
