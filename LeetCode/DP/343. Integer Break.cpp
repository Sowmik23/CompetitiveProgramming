class Solution {
public:
    int integerBreak(int n) {
        
        //classic rod cutting problem
        
        //Recursion: accepted
        //return dpRecursion(n, n-1);
    
        //Memoization: 
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        return dp(n, memo, n-1);
    }
private:
    int dpRecursion(int n, int i){
        if(n==0 or i==0) return 1;
        
        if(i>n) return dpRecursion(n, i-1);
        
        return max(i*dpRecursion(n-i, i), dpRecursion(n, i-1));
    }
    
    int dp(int n, vector<vector<int>> &memo, int i){
        if(i==0 or n==0) return memo[i][n] = 1;
        
        if(memo[i][n]!=-1) return memo[i][n];
        if(i>n) return memo[i][n] = dp(n, memo, i-1);
        
        return memo[i][n] = max(i*dp(n-i, memo, i), dp(n, memo, i-1));
    }
};
