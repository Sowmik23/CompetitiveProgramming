class Solution {
public:
    int climbStairs(int n) {

        //TLE
        // return recursive(n);

        //recursion with memoization
        // vector<int> memo(n+1, -1);
        // return recursionWithMemoization(n, memo);

        //tabulation
        int a = 1;
        int b = 1;

        if(n==1) return 1;

        int c;
        for(int i=2;i<=n;i++){
            c = a+b;
            b = a;
            a = c;
        }

        return c;
    }
private:
    int recursive(int n){
        if(n<=3) return n;
        return recursive(n-1)+recursive(n-2);
    }
    int recursionWithMemoization(int n, vector<int> &memo){
        if(n<=3) return n;
        if(memo[n]!=-1)return memo[n];
        return memo[n] = recursionWithMemoization(n-1, memo) + recursionWithMemoization(n-2, memo);
    }
};
