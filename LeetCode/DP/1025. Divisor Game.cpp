class Solution {
public:
    bool divisorGame(int n) {
        
        //Approach-01: recursion: Accepted
        //return recursive(n, 0);
        
        
        //Approach-02: recursion with memoization
        //vector<vector<int>> memo(n+3, vector<int> (2, -1));
        //return recursionWithMemo(n, memo, 0);
    
        //Tabulation
        return tabulation(n);
    }
private:
    //Recursion
    bool recursive(int n, int alice){
        if(n==1 and alice==0) return false;
        if(n==1 and alice==1) return true;
        
        //first of all find all the divisors of n 
        for(int i=1;i*i<=n;i++){
            if(n%i==0) return recursive(n-i, alice==0 ? 1: 0);
        }
        
        return alice==0 and n==1;
    }
    
    
    //Recursion with memoization
    bool recursionWithMemo(int n, vector<vector<int>> &memo, int alice){
        
        if(n==1 and alice==0) return memo[n][0] = 0;
        if(n==1 and alice==1) return memo[n][1] = 1;
        
        if(memo[n][alice]!=-1) return memo[n][alice];
        
        for(int i=1;i*i<=n;i++){
            alice = alice==0 ? 1: 0;
            if(n%i==0) return memo[n-i][alice] = recursionWithMemo(n-i, memo, alice);
        }
        
        return memo[n][alice]==0;
    }
    
    //Tabulation
    bool tabulation(int n){
        vector<vector<int>> dp(n+5, vector<int> (2, 0));
        int alice = 0;
        
        dp[1][0] = 0;
        dp[1][1] = 1;
        for(int j=1;j<=n;j++){
            for(int i=1;i*i<=j;i++){
                if(j%i==0) dp[j][alice] = 1 | dp[j-i][alice];
            }
            alice = alice==0 ? 1: 0;
        }
        
         return dp[n][0]==0;
    }
};
