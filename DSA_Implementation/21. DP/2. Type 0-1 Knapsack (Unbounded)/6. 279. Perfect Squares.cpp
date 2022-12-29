class Solution {
public:
    int numSquares(int n) {

        int m = sqrt(n);

        //recursive: TLE
        //return recursive(n, m);

        //recursion with memoization: Accepted
        // vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        // return recursionWithMemo(memo, n, m);

        //tabulation
//         vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

//         for(int i=0;i<=m;i++) {
//             for(int j=0;j<=n;j++) {
//                 if(i==0 or j==0) dp[i][j]=INT_MAX;
//             }
//         }

//         for(int i=1;i<=m;i++){
//             for(int j=1;j<=n;j++){
//                 int ps=(i*i);
//                 if(ps<=j) dp[i][j] = min(1+(dp[i][j-ps]==INT_MAX ? 0 : dp[i][j-ps]), dp[i-1][j]);
//                 else dp[i][j] = dp[i-1][j];
//             }
//         }
//         return dp[m][n];


        //tabulation with optimized memory
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=m;i++){
            int ps = (i*i);
            for(int j=ps;j<=n;j++){
                dp[j] = min(1+dp[j-ps], dp[j]);
            }
        }
        return dp[n];
    }
private:
    int recursive(int n, int m){

        if(n==0) return 0;
        if(m==0) return INT_MAX;

        if((m*m)>n) return recursive(n, m-1);
        return min(1+recursive(n-(m*m), m), recursive(n, m-1));
    }

    int recursionWithMemo(vector<vector<int>> &memo, int n, int m){
        if(n==0) return 0;
        if(m==0) return INT_MAX;

        if(memo[n][m]!=-1) return memo[n][m];
        if((m*m)>n) return recursionWithMemo(memo, n, m-1);
        return memo[n][m] = min(1+recursionWithMemo(memo,  n-(m*m), m), recursionWithMemo(memo, n, m-1));
    }
};
