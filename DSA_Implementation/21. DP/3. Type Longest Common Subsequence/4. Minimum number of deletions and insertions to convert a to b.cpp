//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

public:
	int minOperations(string str1, string str2)
	{
	    //LCS problem

	    //recursive
	    int lcs = recursive(str1, str2, str1.size(), str2.size());
      return str1.size()+str2.size()-2*lcs;

	    //recursion with memoization
	   vector<vector<int>> memo(str1.size()+1, vector<int> (str2.size()+1, -1));
	   int lcs = recursionWithMemo(str1, str2, memo, str1.size(), str2.size());
     return str1.size()+str2.size()-2*lcs;

	   //tabulation
	   vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
	   for(int i=1;i<=str1.size();i++){
	      for(int j=1;j<=str2.size();j++){
	          if(str1[i-1]==str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
	          else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	      }
	   }
	   int lcs = dp[str1.size()][str2.size()];
	   return str1.size()+str2.size()-2*lcs;

	   //tabulation with optimized memory
	   vector<vector<int>> dp(2, vector<int>(str2.size()+1, 0));
	   for(int i=1;i<=str1.size();i++){
	       for(int j=1;j<=str2.size();j++){
	           if(str1[i-1]==str2[j-1]) dp[i&1][j] = 1 + dp[i&1^1][j-1];
	           else dp[i&1][j] = max(dp[i&1^1][j], dp[i&1][j-1]);
	       }
	   }
	   int lcs = dp[str1.size()&1][str2.size()];
	   return str1.size()+str2.size()-2*lcs;

	}
private:
    int recursive(string str1, string str2, int i, int j){

        if(i==0 or j==0) return 0;

        if(str1[i-1]==str2[j-1]) return 1+recursive(str1, str2, i-1, j-1);
        return max(recursive(str1, str2, i-1, j), recursive(str1, str2, i, j-1));
    }

    int recursionWithMemo(string str1, string str2, vector<vector<int>> &memo, int i, int j){
        if(i==0 or j==0) return 0;
        if(memo[i][j]!=-1) return memo[i][j];

        if(str1[i-1]==str2[j-1]) return  1+recursionWithMemo(str1, str2, memo, i-1, j-1);
        return memo[i][j] = max(recursionWithMemo(str1, str2, memo, i-1, j), recursionWithMemo(str1, str2, memo, i, j-1));
    }
};

//{ Driver Code Starts.
int main()
{


   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";

    }
    return 0;
}


// } Driver Code Ends
