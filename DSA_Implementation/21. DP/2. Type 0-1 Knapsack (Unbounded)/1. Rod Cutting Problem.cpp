// rod cutting problem : unbounded knapsack

#include <bits/stdc++.h>
using namespace std;


//Time: 2^n
int recursive(vector<int> &prices, int length, int len, int i){

    if(len>=length) return 0;
    if(i==0) return 0;

    int cut = 0, notCut = 0;
    if(len+i<=length) cut = prices[i-1]+recursive(prices, length, len+i, i);
    notCut = recursive(prices,  length,  len, i-1);

    return max(cut, notCut);
}

//Time: n*sum => n^2
int recursionWithMemo(vector<int> &prices, vector<vector<int>> &memo, int length, int len, int i){

    if(len>=length) return 0;
    if(i==0) return 0;

    if(memo[i-1][len]!=-1) return memo[i-1][len];

    int cut =0, notCut = 0;
    if(i+len<=length) cut = prices[i-1]+recursionWithMemo(prices, memo, length, i+len, i);
    notCut = recursionWithMemo(prices, memo, length, len, i-1);
    memo[i-1][len] = max(cut, notCut);

    return memo[i-1][len];
}


int maxProfit(vector<int> &prices, int length){

    //base case
    if(length==1) return prices[0];

    //recursion.
    // return recursive(prices, length, 0, length);

    //recursion with memoization
    // vector<vector<int>> memo(length,  vector<int> (length, -1));
    // return recursionWithMemo(prices, memo, length,  0, length);

    //tabulation: Time: O(n^2)
    vector<int> dp(length, 0);
    dp[0] = 0;

    for(int i=1;i<=length;i++){
        int mx = INT_MIN;
        for(int j=0;j<i;j++){
            mx = max(mx, prices[j]+dp[i-j-1]);
        }
        dp[i] = mx;
    }
    return dp[length];
}


int main()
{
    vector<int> prices = {1,   5,   8,   9,  10,  17,  17,  20};
    int length = 8;
    cout<<maxProfit(prices, length)<<endl; // 22

    prices ={3,   5,   8,   9,  10,  17,  17,  20};
    length = 8;
    cout<<maxProfit(prices, length)<<endl; // 24

    return 0;
}
