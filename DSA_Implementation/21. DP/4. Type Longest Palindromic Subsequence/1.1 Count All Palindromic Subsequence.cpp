//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:

    const long mod = 1e9+7;
    long long int  countPS(string str)
    {

       //Time: O(n^2)
        //   return recursive(str, 0, str.size()-1);

       //recursive with memo: TLE
        //   vector<vector<int>> memo(str.size()+1, vector<int>(str.size()+1, -1));
        //   return recursionWithMemo(str, memo, 0, str.size()-1);

        //tabulation
        vector<vector<long long int>> dp(str.size()+1, vector<long long int>(str.size()+1, 0));
        for(int i=0;i<str.size();i++) dp[i][i] = 1; //1 char is a palindrome

        //k is the length of each substring
        for(int k=2;k<=str.size();k++){
            for(int i=0;i<=str.size()-k;i++){
                int j = i+k-1; //length of each substring where i is the start position
                if(str[i]==str[j]) dp[i][j] = (1+dp[i+1][j]%mod + dp[i][j-1]%mod)%mod;
                else dp[i][j] = (dp[i+1][j]%mod + dp[i][j-1]%mod - dp[i+1][j-1]%mod)%mod;
            }
        }

        return dp[0][str.size()-1]%mod;
    }
private:
    long long int recursive(string str, int i, int j){

        if(i>j) return 0;
        if(i==j) return 1;
        if(str[i]==str[j]) return 1+recursive(str, i+1, j)+recursive(str, i, j-1);
        return recursive(str, i+1, j) + recursive(str, i, j-1) - recursive(str, i+1, j-1);
    }
    long long recursionWithMemo(string str, vector<vector<int>> &memo, int i, int j){
        if(i>j) return 0;

        if(memo[i][j]!=-1) return memo[i][j];

        if(i==j) return 1;
        if(str[i]==str[j]) return memo[i][j] = 1+recursionWithMemo(str, memo, i+1, j) + recursionWithMemo(str, memo, i, j-1);
        return memo[i][j] = recursionWithMemo(str, memo, i+1,j) + recursionWithMemo(str, memo, i, j-1) - recursionWithMemo(str, memo, i+1, j-1);
    }
};


//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
