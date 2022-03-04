class Solution {
public:
    bool winnerSquareGame(int n) {
        
        //Dynamic Programming
        
        
        //recursive approach: TLE
//         if(n==0) return false;
//         bool winner = false;
        
//         for(int i=1;i*i<=n;i++){
//             if(winnerSquareGame(n-i*i)==false){
//                 winner = true;
//                 break;
//             }
//         }
        
//         return winner;
        
        
        
        //recursion with memoization
//         vector<int> dp(n+1, -1);
//         return recursionWithMemoization(n, dp);
        
        
        //tabulation
        vector<bool> dp(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(dp[i-j*j]==false){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
    
private:
    bool recursionWithMemoization(int n, vector<int> &dp){
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        
        bool winner = false;
        for(int i=1;i*i<=n;i++){
            if(recursionWithMemoization(n-i*i, dp)==false){
                dp[n] = true;
                winner = true;
                break;
            }
        }
        
        return dp[n] = winner;
    }
};
