class Solution {
public:
    int countPalindromicSubsequences(string s) {

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=0;i<n; i++){
            dp[i][i] = 1; //every single char is palindromic
        }
        for(int k = 1; k < n; k++){
            for(int i = 0; i < n - k; i++){
                int j = i+k;
                if(s[i] == s[j]){
                    int low = i+1, high = j-1;
                    while(low <= high && s[low] != s[i]) low++;
                    while(low <= high && s[high] != s[j]) high--;
                    if(low > high){
                        //there are all different characters between s[i] and s[j]
                        // without taking s[i] and s[j] there were dp[i+1][j-1] plaindromic subseq no we have all palindromic subseq before + s[i] + all palindromic subseq before + s[j] = dp[i + 1][j - 1] * 2 + 1 for s[i] && 1 for s[i]s[j]

                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    }
                    else if(low == high){
                         //there's only one character at centre that is = s[i]
                        //there are all different characters between s[i] and s[j]
                        // without taking s[i] and s[j] there were dp[i+1][j-1] plaindromic subseq no we have all palindromic subseq before + s[i] + all palindromic subseq before + s[j] = dp[i + 1][j - 1] * 2 + 1 for s[i]s[j] as s[i] is already counted before
                         dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    }
                    else{
                        //characters are repeating
                        //eg aaabcbaaa ans is ans of aaabcbaaa - ans of aabcbaa
                         dp[i][j] = dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1];
                    }
                }
                else{
                  dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + 1000000007 : dp[i][j] % 1000000007;
            }
        }
        return dp[0][n-1];
    }
};
