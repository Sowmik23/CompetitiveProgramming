class Solution {
public:
    long mod = (2 * 1e9) + 1;
    int uniquePaths(int m, int n) {

        //recursive
        // return recursive(m-1, n-1);

        //recursion with memoization
        // vector<vector<int>> memo(m, vector<int>(n, -1));
        // return recursionWithMemo(memo, m-1, n-1);

        //tabulation
        vector<vector<int>> dp(m+1, vector<int> (n+1, 1));
        // dp[0][0] = 1;
        // dp[0][1] = 1;
        // dp[1][0] = 1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            }
        }
        return dp[m-1][n-1]%mod;
    }
private:
    int recursive(int m, int n){
        if(m<0 or n<0) return 0;
        if(m==0 and n==0) return 1;

        return recursive(m-1, n)%mod + recursive(m, n-1)%mod;
    }

    int recursionWithMemo(vector<vector<int>> &memo, int m, int n){
        if(m<0 or n<0) return 0;
        if(m==0 and n==0) return 1;

        if(memo[m][n]!=-1) return memo[m][n];
        memo[m][n] = recursionWithMemo(memo, m-1, n)%mod + recursionWithMemo(memo, m, n-1)%mod;
        return memo[m][n];
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> memo(m, vector<int>(n, -1));

        return paths(memo, m-1, n-1);
    }
private:
    //recursion
    int paths1(int m, int n){

        if(m<0 or n<0) return 0;
        if(m==0 and n==0) return 1;

        return paths1(m-1, n) + paths1(m, n-1);
    }

    //recursion with memoization
    int paths(vector<vector<int>> &memo, int m, int n){
        if(m<0 or n<0) return 0;
        if(m==0 and n==0) return 1;

        if(memo[m][n]!=-1) return memo[m][n];

        int res = paths(memo, m-1, n) + paths(memo, m, n-1);
        memo[m][n] = res;

        return memo[m][n];
    }
};
