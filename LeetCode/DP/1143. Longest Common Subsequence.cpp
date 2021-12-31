class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> memo(text1.size()+1, vector<int>(text2.size()+1, -1));
        return dp(text1, text2, memo, 0, 0);
    }
private:
    int dp(string& str1, string &str2, vector<vector<int>> &memo, int i, int j){

        if(i>=str1.size() or j>=str2.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        
        if(str1[i]==str2[j]){
            return memo[i][j] = 1+dp(str1, str2, memo, i+1, j+1);
        }
        
        else return memo[i][j] = max(dp(str1, str2, memo, i+1, j), dp(str1, str2, memo, i, j+1));
    }
};
