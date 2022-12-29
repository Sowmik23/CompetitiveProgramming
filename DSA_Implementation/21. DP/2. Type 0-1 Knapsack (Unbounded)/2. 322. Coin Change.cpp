// 322. Coin Change

#include <bits/stdc++.h>
using namespace std;

int recursive(vector<int> &coins, int amount, int i){

    if(amount==0) return 0;
    if(i==0) return INT_MAX-1;

    if(coins[i-1]>amount) return recursive(coins, amount, i-1);
    return min(1+recursive(coins, amount-coins[i-1], i), recursive(coins, amount, i-1));
}

int recursionWithMemo(vector<int> &coins, int amount, vector<vector<int>> &memo, int i){

    if(amount==0) return 0;
    if(i==0) return INT_MAX-1;

    if(memo[i-1][amount]!=-1) return memo[i-1][amount];

    if(coins[i-1]>amount) return recursionWithMemo(coins, amount, memo, i-1);
    return memo[i-1][amount] = min(1+recursionWithMemo(coins, amount-coins[i-1], memo, i), recursionWithMemo(coins, amount, memo, i-1));
}


int minCoinToMakeAmount(vector<int> &coins, int amount){

    // //recursion
    // return recursive(coins, amount, coins.size());

    // //recursion with memoization
    // vector<vector<int>> memo(coins.size(), vector<int> (amount+1, -1));
    // return recursionWithMemo(coins, amount, memo, coins.size());

    // //tabulation
    vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1, 0));

    // //base case:
    for(int i=0;i<=amount;i++) dp[0][i]=INT_MAX-1;
    for(int i=1;i<=coins.size();i++) dp[i][0] = 0;

    for(int i=1;i<=coins.size();i++){
        for(int j=1;j<=amount;j++){
            if(coins[i-1]>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
        }
    }
    return dp[coins.size()][amount]==INT_MAX-1 ? -1 :  dp[coins.size()][amount];

    // //tabulation with optimized memory(have problem)
    vector<int> dp(amount+1);

    // //base case
    for(int i=0;i<=amount;i++) dp[i] = INT_MAX-1;

    for(int i=1;i<=coins.size();i++){
        for(int j=coins[i-1];j<=amount;j++){
            dp[j] = min(1+dp[j-coins[i-1]], dp[j]);
        }
    }
    return dp[amount]==INT_MAX-1 ? -1 :  dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int res = minCoinToMakeAmount(coins, amount);
    res = res==INT_MAX-1 ? -1 : res;
    cout<<res<<endl; //3

    coins = {2};
    amount = 3;
    res = minCoinToMakeAmount(coins, amount);
    res = res==INT_MAX-1 ? -1 : res;
    cout<<res<<endl; //-1

    coins = {1};
    amount = 0;
    res = minCoinToMakeAmount(coins, amount);
    res = res==INT_MAX-1 ? -1 : res;
    cout<<res<<endl; //0

    return 0;
}
