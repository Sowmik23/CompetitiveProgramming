 // Given two string X and Y of length N and M respectively. The task is to find the length
 // of the longest subsequence of string X which is a substring in sequence Y.

// PREREQUISITES: Longest common subsequence problem will help you understand this problem in a snap 🙂


//{ Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int maxSubsequenceSubstring(string x, string y, int n, int m);

// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

int recursive(string str1, string str2, int i, int j);
int recursionWithMemo(string str1, string str2, vector<vector<int>> &memo, int i, int j);


int maxSubsequenceSubstring(string X, string Y, int N, int M){

    int res = 0;

    vector<vector<int>> memo(N+1, vector<int> (M+1, -1));
    // //recursion and recursion with memoization
    for(int i=Y.size();i>=0;i--){
        // res = max(res, recursive(X, Y, N, i));  //recursive
        res = max(res, recursionWithMemo(X, Y, memo, N, i));
    }
    return res;

    vector<vector<int>> dp(N+1, vector<int> (M+1, 0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(X[i-1]==Y[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j];
        }
    }
    int mx = 0;
    for(int i=0;i<=M;i++){
        mx = max(mx, dp[N][i]);
    }
    return mx;
}

//TLE
int recursive(string str1, string str2, int i, int j){
    if(i==0 or j==0) return 0;

    if(str1[i-1]==str2[j-1]) return 1+recursive(str1, str2, i-1, j-1);
    return recursive(str1,str2, i-1, j);
}

//TLE
int recursionWithMemo(string str1, string str2, vector<vector<int>> &memo, int i, int j){

    if(i==0 or j==0) return 0;
    if(memo[i][j]!=-1) return memo[i][j];

    if(str1[i-1]==str2[j-1]) return memo[i][j] = 1+recursionWithMemo(str1, str2, memo, i-1, j-1);
    return memo[i][j] = recursionWithMemo(str1, str2, memo, i-1, j);
}
