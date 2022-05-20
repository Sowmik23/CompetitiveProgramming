class Solution {
public:
    int fib(int n) {
        
        /*
        vector<int> dp(n+2, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp[n];
        */
        
        /*
        if(n<2) return n;
        int a = 0;
        int b = 1;
        int c;
        for(int i=2;i<=n;i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
        */
        if(n<2) return n;
        return fibo(n);
    }
private:
    int fibo(long a){
        if(a==0) return 0;
        if(a==1) return 1;
        
        return fibo(a-1)+fibo(a-2);
    }
};
