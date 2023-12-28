//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int recursive(string str1, string str2, int i, int j);
int recursionWithMemo(string str1, string str2, vector<vector<int>> &memo, int i, int j);

int minDeletions(string str, int n) {

    //same: LCS (find LCS of str and reverse of str. Then delete n-LCS)
    string str2 = str;
    reverse(str.begin(), str.end());

    //recursive: TLE
    // int x = recursive(str, str2, n, n);

    //recursion with memoization: TLE
    // vector<vector<int>> memo(n+1, vector<int> (n+1, -1));
    // int x = recursionWithMemo(str, str2,memo, n, n);

    //tabulation
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(str[i-1]==str2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int x = dp[n][n];

    return n-x;
}
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
