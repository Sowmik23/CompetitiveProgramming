class Solution {
public:
    int minDistance(string word1, string word2) {
     
        //first find the maximum common subsequence
        //then delete maximum common subsequence from both string
        
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        return m+n-2*dp(word1, word2, memo, 0, 0);
    }
private:
    int dp(string &word1, string &word2, vector<vector<int>> &memo, int i, int j){
        
        if(i>=word1.size() or j>=word2.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        
        if(word1[i]==word2[j]) return memo[i][j] = 1+dp(word1, word2, memo, i+1, j+1);
        else return memo[i][j] = max(dp(word1, word2, memo, i+1, j), dp(word1, word2, memo, i, j+1));
    }
};
