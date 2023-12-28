//Return the number of combinations that make up that amount
//you have an infinite number of each kind of coin.


class Solution {
public:
    int change(int amount, vector<int>& coins) {


        //recursive: TLE
        // return recursive(coins, amount, coins.size());

        //recursion with memoization
        // vector<vector<int>> memo(coins.size(), vector<int> (amount+1, -1));
        // return recursionWithMemo(coins, memo, amount, coins.size());


        // tabulation
//         vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1,  -1));
//         //base case
//         for(int i=1;i<=coins.size();i++) dp[i][0] = 1;
//         for(int i=0;i<=amount;i++) dp[0][i] = 0;

//         for(int i=1;i<=coins.size();i++){
//             for(int j=1;j<=amount;j++){
//                 if(coins[i-1]<=j) dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
//                 else dp[i][j] = dp[i-1][j];
//             }
//         }
//         return dp[coins.size()][amount];


        //tabulation with optimized memory
        vector<int> dp(amount+1, 0);
        //base case
        dp[0] = 1;
        for(int i=1;i<=coins.size();i++){
            for(int j=coins[i-1];j<=amount;j++){
                dp[j] = dp[j] + dp[j-coins[i-1]];
            }
        }
        return dp[amount];
    }
private:
    int recursive(vector<int> &coins, int amount, int i){

        if(amount==0) return 1;
        if(i==0) return 0;

        int taken = 0, notTaken = 0;
        if(coins[i-1]<=amount) taken += recursive(coins, amount-coins[i-1], i);
        notTaken += recursive(coins, amount, i-1);

        return taken+notTaken;
    }

    int recursionWithMemo(vector<int> &coins, vector<vector<int>> &memo, int amount, int i){
        if(amount==0) return 1;
        if(i==0) return 0;

        if(memo[i-1][amount]!=-1) return memo[i-1][amount];
        memo[i-1][amount]  = 0;
        if(coins[i-1]<=amount) memo[i-1][amount] +=recursionWithMemo(coins, memo, amount-coins[i-1], i);
        memo[i-1][amount]+=recursionWithMemo(coins, memo, amount, i-1);
        return memo[i-1][amount];
    }
};
