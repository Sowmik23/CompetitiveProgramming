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
