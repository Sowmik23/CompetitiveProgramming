class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        // recursion: TLE
        // return min(dp(0, cost), dp(1, cost));
        
        
        // recursion with memoization : Accepted
        // vector<int> memo(cost.size()+2, -1);
        // return min(dpWithMemoization(0, cost, memo), dpWithMemoization(1, cost, memo));
        
        //Tabulation
        return dpTabulation(cost);
    }
private:
    //recursion
    int dp(int i, vector<int> &cost){
        
        if(i>=cost.size()) return 0;
        
        return min(dp(i+1, cost)+cost[i], dp(i+2, cost)+cost[i]);
    }
    
    //recursion with memoization
    int dpWithMemoization(int i, vector<int> & cost, vector<int> &memo){
        
        if(i>=cost.size()) return 0;
        
        if(memo[i]!=-1) return memo[i];
        
        return memo[i] = min(dpWithMemoization(i+1, cost, memo)+cost[i], dpWithMemoization(i+2, cost, memo)+cost[i]);
    }
    
    //tabulation
    int dpTabulation(vector<int> &cost){
        vector<int> memo(cost.size()+2, 0);
        vector<int> memo1(cost.size()+2, 0);
        memo[cost.size()]= 0;
        
        for(int i=cost.size()-1;i>=0;i--){
            memo[i] = min(memo[i+1]+cost[i], memo[i+2]+cost[i]);
        }
        for(int i=cost.size()-1;i>=1;i--){
            memo1[i] = min(memo1[i+1]+cost[i], memo1[i+2]+cost[i]);
        }
        return min(memo[0], memo1[1]);
    }
};
