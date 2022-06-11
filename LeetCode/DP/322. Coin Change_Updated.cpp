class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int res;
        
        //recursion : TLE
//         res = dp(coins, amount, coins.size());  
//         if(res==INT_MAX-1) return -1;
//         return res;
        
        //recursion with memoization: Accepted
        vector<vector<int>> memo(amount+1, vector<int> (coins.size()+1, -1));
        
        res = dpWithMemo(coins, amount, memo, coins.size());
        
        if(res==INT_MAX-1) return -1;
        return res;
        
    }
private:
    //recursion : TLE
    int dp(vector<int> &coins, int amount, int i){
        
        if(i==0 or amount==0){
            if(amount==0) return 0;
            else return INT_MAX-1;
        }
        
        if(coins[i-1]>amount) return 0+dp(coins, amount, i-1);
        else return min(dp(coins, amount, i-1), 1+dp(coins, amount-coins[i-1], i));
    }
    
    //recursion with memoization
    int dpWithMemo(vector<int> &coins, int amount, vector<vector<int>>&memo, int i){
        if(i==0 and amount!=0) return INT_MAX-1;
        if(i==0 and amount==0) return  0;
        
        if(memo[amount][i]!=-1) return memo[amount][i];
        
        if(coins[i-1]>amount) return memo[amount][i] = dpWithMemo(coins, amount, memo, i-1);
        else return memo[amount][i] = min(dpWithMemo(coins, amount, memo, i-1), 1+dpWithMemo(coins, amount-coins[i-1], memo, i));
        
    }
};
