// 2742. Painting the Walls

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        

        //Dynamic Programming
        int n = cost.size();

        //recursive/Top down
        // return recursive(0, n, cost, time);

        //recursion with memoization Time: O(n^2)
        // vector<vector<int>> memo(n+1, vector<int> (n+1, -1));
        // return recursionWithMemo(0, n, cost, time, memo);

        //tabulation/Bottom-up
        // Time: O(n^2)
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        //base case
        for(int i=1;i<=n;i++) dp[n][i] = 1e9;

        for(int i=n-1;i>=0;i--){
            for(int remain=1;remain<=n;remain++){
                int paint = cost[i] + dp[i+1][max(0, remain-1-time[i])];
                int dontPaint = dp[i+1][remain];
                dp[i][remain] = min(paint, dontPaint);
            }
        }
        return dp[0][n];
    }
private:
    int recursive(int index, int remaining, vector<int> &cost, vector<int> &time){
        if(remaining<=0) return 0;
        if(index==cost.size()) return 1e9;
        int paint = cost[index] + recursive(index+1, remaining-1-time[index], cost, time);
        int dontPaint = recursive(index+1, remaining, cost, time);

        return min(paint, dontPaint);
    }
    int recursionWithMemo(int i, int remaining, vector<int>&cost, vector<int>&time, vector<vector<int>>&memo){
        if(remaining<=0) return 0;
        if(i==cost.size()) return 1e9;

        if(memo[i][remaining]!=-1) return memo[i][remaining];

        int paint = cost[i]+recursionWithMemo(i+1, remaining-1-time[i], cost, time, memo);
        int dontPaint = recursionWithMemo(i+1, remaining, cost, time, memo);

        return memo[i][remaining] = min(paint, dontPaint);
    }
};