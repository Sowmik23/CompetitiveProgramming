//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


// Given two strings S1 and S2, find the number of times the second
// string occurs in the first string, whether continuous or discontinuous.



class Solution{
public:
    int countWays(string S1, string S2){

        //Accepted
        return recursive(S1, S2, S1.size(), S2.size());

        //recursion With Memoization
        vector<vector<int>> memo(S1.size()+1, vector<int> (S2.size()+1, -1));
        return recursionWithMemo(S1, S2, memo, S1.size(), S2.size());


        //tabulation
        vector<vector<int>> dp(S1.size()+1, vector<int> (S2.size()+1, 0));
        //if the first string is empty
        for(int i=0;i<=S2.size();i++) dp[0][i] = 0;
        //if the second string(which subsequence) is empty
        for(int i=0;i<=S1.size();i++) dp[i][0] = 1;

        for(int i=1;i<=S1.size();i++){
            for(int j=1;j<=S2.size();j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[S1.size()][S2.size()];
    }
private:
    int recursive(string str1, string str2, int i, int j){
        if(j==0) return 1;
        if(i==0) return 0;

        if(str1[i-1]==str2[j-1]) return recursive(str1, str2, i-1, j-1)+recursive(str1, str2, i-1, j);
        return recursive(str1, str2, i-1, j);
    }
    int recursionWithMemo(string str1, string str2, vector<vector<int>> &memo, int i, int j){
        if(j==0) return 1;
        if(i==0) return 0;

        if(memo[i][j]!=-1) return memo[i][j];
        if(str1[i-1]==str2[j-1]) return memo[i][j] = recursionWithMemo(str1, str2, memo, i-1, j-1)+recursionWithMemo(str1, str2, memo, i-1, j);
        return memo[i][j] = recursionWithMemo(str1, str2, memo, i-1,  j);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends
