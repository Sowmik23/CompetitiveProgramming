//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Longest Repeating subsequence

// This problem is just the modification of Longest Common Subsequence problem.
// The idea is to find the LCS(str, str) where, str is the input string with the restriction
// that when both the characters are same, they shouldn’t be on the same index in the two strings.

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    //recursive
            //return recursive(str, str, str.size(), str.size());

            //recursionWithMemo
            // vector<vector<int>> memo(str.size()+1, vector<int> (str.size()+1, -1));
            // return recursionWithMemo(str, str, memo, str.size(), str.size());

            //tabulation
            // int n = str.size();
            // vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
            // for(int i=1;i<=n;i++){
            //     for(int j=1;j<=n;j++){
            //         if(str[i-1]==str[j-1] and i!=j) dp[i][j] = 1+dp[i-1][j-1];
            //         else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            //     }
            // }
            // return dp[n][n];

            //tabulation with optimized memory
            int n = str.size();
            vector<vector<int>> dp(2, vector<int> (n+1, 0));
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(str[i-1]==str[j-1] and i!=j) dp[i&1][j] = 1+dp[i&1^1][j-1];
                    else dp[i&1][j] = max(dp[i&1^1][j], dp[i&1][j-1]);
                }
            }
            return dp[n&1][n];
		}
    private:
    int recursive(string str1, string str2, int i, int j){
        if(i==0 or j==0) return 0;

        if(str1[i-1]==str2[j-1] and i!=j) return 1+recursive(str1, str2, i-1, j-1);
        return max(recursive(str1, str2,  i-1, j), recursive(str1, str2, i, j-1));
    }

    int recursionWithMemo(string str1, string str2, vector<vector<int>> &memo, int i, int j){
        if(i==0 or j==0) return 0;
        if(memo[i][j]!=-1) return memo[i][j];

        if(str1[i-1]==str2[j-1] and i!=j) return 1+recursionWithMemo(str1, str2, memo, i-1, j-1);
        return memo[i][j] = max(recursionWithMemo(str1, str2, memo, i-1, j), recursionWithMemo(str1, str2, memo, i, j-1));
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
