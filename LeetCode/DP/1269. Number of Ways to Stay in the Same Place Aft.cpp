// 1269. Number of Ways to Stay in the Same Place After Some Steps

class Solution {
public:
    int numWays(int steps, int arrLen) {

       //Dynamic Programming
       //Awesome problem

       // case: Notice in the constraints that while steps can be up to 500, 
       // arrLen can be up to 10^6 

        int n = min(steps, arrLen);

        //recursive
        //Time: 3^n as recursion function calls 3 times
        // return recursive(0, steps, n);

        //recursion with memoization: Memory Limit Exceed
        // Time: steps*(min(steps, arrLen))
        // vector<vector<int>> memo(arrLen+1, vector<int> (steps+1, -1));
        // return recursionWithMemo(0, steps, n, memo);

        //tabulation: Bottom up
        vector<vector<int>> dp(n+1, vector<int> (steps+1, 0));
        dp[0][0] = 1;
        for(int remain=1;remain<=steps;remain++){
            for(int curr=n-1;curr>=0;curr--){
                int cnt = dp[curr][remain-1];

                if(curr>0) cnt = (cnt+dp[curr-1][remain-1])%mod;
                if(curr<n-1) cnt = (cnt+dp[curr+1][remain-1])%mod;

                dp[curr][remain] = cnt; 
            }
        }
        return dp[0][steps];
    }
private:
    const int mod = 1e9+7;

    int recursive(int curr, int remainSteps, int totalSteps){
        if(remainSteps==0){
            if(curr==0) return 1;
            else return 0;
        }

        int cnt = recursive(curr, remainSteps-1, totalSteps); //stay there
        if(curr>0) cnt+=recursive(curr-1, remainSteps-1, totalSteps); //move left
        if(curr<totalSteps-1) cnt+=recursive(curr+1, remainSteps-1, totalSteps); //move right

        return cnt;
    }

    int recursionWithMemo(int curr, int remainSteps, int totalSteps, vector<vector<int>>&memo){
        if(remainSteps==0) {
            if(curr==0) return 1;
            else return 0;
        }
        if(memo[curr][remainSteps]!=-1) return memo[curr][remainSteps];

        int cnt = recursionWithMemo(curr, remainSteps-1, totalSteps, memo)%mod; //stay there
        if(curr>0) cnt = (cnt+recursionWithMemo(curr-1, remainSteps-1, totalSteps, memo))%mod; //move left
        if(curr<totalSteps-1) cnt = (cnt + recursionWithMemo(curr+1, remainSteps-1, totalSteps, memo))%mod; //move right

        return memo[curr][remainSteps] = cnt%mod;
    }
};