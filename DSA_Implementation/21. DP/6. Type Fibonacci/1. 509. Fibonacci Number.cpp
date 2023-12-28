class Solution {
public:
    int fib(int n) {


        // recursion
        return dp(n);

        //recursion with memoizaton
        // vector<int> memo(n+2, -1);
        // return dpwithMemoization(n, memo);

        //tabulation
        return dpTabulation(n);
    }
private:
    //recursion
    int dp(int n){
        if(n<=1) return n;

        return dp(n-1)+dp(n-2);
    }

    int dpwithMemoization(int n, vector<int> &memo){

        if(n<=1) return n;
        if(memo[n]!=-1) return memo[n];
        return memo[n] = dpwithMemoization(n-1, memo)+dpwithMemoization(n-2, memo);
    }

    int dpTabulation(int n){
        if(n<=1) return n;
        else {
            int c, a = 0, b = 1;
            while(n>=2){
                c = a+b;
                b = a;
                a = c;
            }

            return c;
        }
    }
};
