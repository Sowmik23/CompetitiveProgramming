
#include <bits/stdc++.h>
using namespace std;


int recursive(string str1, string str2, int i, int j, int cnt){
    if(i==0 or j==0) return cnt;

    if(str1[i-1]==str2[j-1]) return recursive(str1, str2, i-1, j-1, cnt+1);
    return max(cnt, max(recursive(str1, str2, i-1, j, 0), recursive(str1, str2, i, j-1, 0)));
}

int recursionWithMemoization(vector<vector<vector<int>>> &memo, string str1, string str2, int i, int j, int cnt){

    if(i==0 or j==0) return cnt;
    if(memo[i-1][j-1][cnt]!=-1) return memo[i-1][j-1][cnt];

    if(str1[i-1]==str2[j-1]){
        return recursionWithMemoization(memo, str1, str2, i-1, j-1, cnt+1);
    }
    return memo[i-1][j-1][cnt] = max({cnt, recursionWithMemoization(memo, str1, str2, i-1, j, 0), recursionWithMemoization(memo, str1, str2, i, j-1, 0)});
}

int lCSstring(string str1, string str2){


    // //recursive
    return recursive(str1, str2, str1.size(), str2.size(), 0);

    // //recursion with memoization: Time: O(N * M* max(M,N))
    vector<vector<vector<int>>> memo(str1.size()+1, vector<vector<int>>(str2.size()+1, vector<int> (str1.size()+1, -1)));
    return recursionWithMemoization(memo, str1,  str2, str1.size(), str2.size(), 0);


    // //tabulation
    vector<vector<int>> dp(str1.size()+1, vector<int> (str2.size()+1, 0));
    int res = 0;
    for(int i=1;i<=str1.size();i++){
        for(int j=1;j<=str2.size();j++){
            if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            // else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            res = max(res, dp[i][j]);
        }
    }
    // return dp[str1.size()][str2.size()];
    return res;

    // //tabulation with optimized memory
    vector<vector<int>> dp(2, vector<int>(str2.size()+1, 0));
    int res = 0;
    for(int i =1;i<=str1.size();i++){
        for(int j=1;j<=str2.size();j++){
            if(str1[i-1]==str2[j-1]) dp[i&1][j] = 1+dp[i&1^1][j-1];
            // else dp[i&1][j] = max(dp[i&1^1][j], dp[i&1][j-1]);
            res = max(res, dp[i&1][j]);
        }
    }
    // return dp[str1.size()&1][str2.size()];
    return res;
}


int main()
{
    string str1 = "GeeksforGeeks";
    string str2 = "GeeksQuiz";
    cout<<lCSstring(str1, str2)<<endl; //5

    str1 = "abcdxyz";
    str2 = "xyzabcd";
    cout<<lCSstring(str1, str2)<<endl;  //4

    str1 = "zxabcdezy";
    str2 = "yzabcdezx";
    cout<<lCSstring(str1, str2)<<endl; //6

    return 0;
}
