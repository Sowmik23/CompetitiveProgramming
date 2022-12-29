class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //recursion
        //return min(recursive(cost, 0), recursive(cost, 1));

        //recursiion with memoization
        // vector<int> memo(cost.size()+1,-1);
        // return min(recursionWithMemozation(cost, memo, 0), recursionWithMemozation(cost, memo, 1));

        //tabulation
        vector<int> dp(cost.size()+1);
        dp[0] = cost[0];
        dp[1]= cost[1];
        for(int i=2;i<cost.size();i++){
            dp[i]  = cost[i]+min(dp[i-1], dp[i-2]);
        }
        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
private:
    int recursive(vector<int> &cost, int i){
        if(i>=cost.size()) return 0;

        int x = min(recursive(cost, i+1)+cost[i], recursive(cost, i+2)+cost[i]);
        return x;
    }

    int recursionWithMemozation(vector<int> &cost, vector<int> &memo, int i){
        if(i>=cost.size()) return 0;

        if(memo[i]!=-1) return memo[i];
        memo[i] = min(recursionWithMemozation(cost, memo, i+1)+cost[i], recursionWithMemozation(cost, memo, i+2)+cost[i]);
        return memo[i];
    }
};





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
