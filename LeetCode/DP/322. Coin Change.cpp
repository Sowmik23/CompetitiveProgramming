class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> memo(coins.size()+1, vector<int>(amount+2, -1));
        
        int res= dp(coins, memo, 0, amount);
        if(res!=INT_MAX-1) return res;
        return -1;
    }
private:
    int dp(vector<int> &coins, vector<vector<int>> &memo, int i, int amount){
        
        if(i>=coins.size() or amount<0) return memo[i][amount] = INT_MAX-1;
        if(amount==0) return memo[i][amount] = 0;
        
        if(memo[i][amount]!=-1) return memo[i][amount];
        
        if(coins[i]>amount) return memo[i][amount] = 0+dp(coins, memo, i+1, amount);
        else return memo[i][amount] = min(dp(coins, memo, i+1, amount), 1+dp(coins, memo, i, amount-coins[i]));
    }
};
