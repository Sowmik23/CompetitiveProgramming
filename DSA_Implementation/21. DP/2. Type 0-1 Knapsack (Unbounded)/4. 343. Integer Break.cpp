class Solution {
public:
    int integerBreak(int n) {

        // recursive
        //return recursiveTest(n, n, 1); //TLE
        //return recursive(n, n-1); //Accepted //here we pass n-1 as k>=2. if i==n then it would be a case but it will violent the condition k>=2.

        // recursion with memoization
        // vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        // return recursionWithMemo(memo, n, n-1);


        //tabulation: it's amazing!!! codeeeeeeeeddddd in onee goooooo......!
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
//         for(int i=0;i<=n;i++) dp[i][0] = 1;
//         for(int i=0;i<n;i++) dp[0][i] = 1;

//         for(int i=1;i<n;i++){
//             for(int j=0;j<=n;j++){
//                 if(i<=j) dp[i][j]  = max(dp[i-1][j], i*dp[i][j-i]);
//                 else dp[i][j] = dp[i-1][j];
//             }
//         }
//         return dp[n-1][n];


        //tabulation with optimized memory
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1;i<n;i++){
            for(int j=i;j<=n;j++){
                dp[j] = max(dp[j], i*dp[j-i]);
            }
        }
        return dp[n];
    }
private:
    int recursiveTest(int n, int m, int i){
        if(m==0) return 1;
        if(m<0 or i>=n) return 0;  //here, i>=n cuz k>=2. so, i!=n

        int taken = 1, notTaken = 1;
        if(i<=m)  taken = i*recursiveTest(n, m-i, i);
        notTaken = recursiveTest(n, m, i+1);

        return max(taken, notTaken);
    }

    int recursive(int n, int i){
        if(n==0 or i==0) return 1;

        int taken = 1, notTaken = 1;
        if(i<=n)  taken = i*recursive(n-i, i);
        notTaken = recursive(n, i-1);

        return max(taken, notTaken);
    }

    int recursionWithMemo(vector<vector<int>> &memo, int n, int i){
        if(n==0 or i==0) return 1;
        if(memo[n][i]!=-1) return memo[n][i];

        int taken = 1, notTaken = 1;
        if(i<=n) taken = i*recursionWithMemo(memo, n-i, i);
        notTaken = recursionWithMemo(memo, n, i-1);

        return memo[n][i] = max(taken, notTaken);
    }
};
