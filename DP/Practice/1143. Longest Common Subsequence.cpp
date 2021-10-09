class Solution {
    /*
    class Solution {
public:
    int dp[1005][1005];
    int LCS(string &s1, string &s2, int i, int j){
        if(i==s1.size() or j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j] = 1+LCS(s1,s2,i+1,j+1);
        else return dp[i][j] = max(LCS(s1,s2,i+1,j),LCS(s1,s2,i,j+1));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int i=0,j=0;
        memset(dp,-1,sizeof(dp));
        return LCS(text1,text2,i,j);
    }
};*/
public:
    int memo[1005][1005];
    int longestCommonSubsequence(string text1, string text2) {
        
        //if(text1.size()<text2.size()) return longestCommonSubsequence(text2, text1);
        
        //Recursion : TLE
        //return dp(0, 0, text1, text2);
        
        // Recursion with Memoization(Top-Down approach) : Stil TLE
        // memo = vector<vector<int>> (1005, vector<int>(1005, -1));
        memset(memo, -1, sizeof(memo));
        return dpMemoization(0, 0, text1, text2);
        
        //Tabulation(Bottom-up approach)
       // return dpTabulation(text1.size(), text2.size(), text1, text2);
    }
private:
    //recursion
    int dp(int i, int j, string text1, string text2){
        
        if(i>=text1.size() or j>=text2.size()) return 0;
        
        if(text1[i]==text2[j]) {
            return 1+ dp(i+1, j+1, text1, text2);
        }
        else {
            return max(dp(i+1, j, text1, text2), dp(i, j+1, text1, text2));
        }
        return 0;
    }
    
    //recursion with memoization
    int dpMemoization(int i, int j, string text1, string text2){
        
        if(i>=text1.size() or j>=text2.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        
        if(text1[i]==text2[j]) {
            return memo[i][j] = 1+ dpMemoization(i+1, j+1, text1, text2);
        }
       return memo[i][j] = max(dpMemoization(i+1, j, text1, text2), dpMemoization(i, j+1, text1, text2));
        
    }
    
    //tabulation
    
};
