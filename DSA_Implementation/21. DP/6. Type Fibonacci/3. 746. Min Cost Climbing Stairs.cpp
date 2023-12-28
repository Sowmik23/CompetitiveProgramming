class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        //TLE
        //return min(recursive(cost, n), recursive(cost, n-1));

        //recursion with memoization
        // vector<int> memo(n+1, -1);
        // return min(recursionWithMemo(cost, memo, n), recursionWithMemo(cost, memo, n-1));

        //tabulation
        vector<int> dp(n+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
private:
    int recursive(vector<int> &cost, int i){
        if(i<=0) return 0;

        return cost[i-1]+min(recursive(cost, i-1), recursive(cost, i-2));
    }
    int recursionWithMemo(vector<int> &cost, vector<int> &memo, int i){
        if(i<=0) return 0;
        if(memo[i]!=-1) return memo[i];
        return memo[i] = cost[i-1]+min(recursionWithMemo(cost, memo, i-1), recursionWithMemo(cost, memo, i-2));
    }
};
