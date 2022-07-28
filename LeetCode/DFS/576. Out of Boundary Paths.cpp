class Solution {
public:
    int memo[51][51][51];
    long long mod = 1e9+7;
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        
        //recursion
        //Time: 4^n
        
        //return recursive(m, n, maxMove, startRow, startColumn);
        
        //recursion with memoization
        //Time: MaxMove*m*n
        //Space: MaxMove*m*n
        
        // vector<vector<vector<int>>> memo(m, vector<int> (n, vector<int>(maxMove, -1)));
        
        memset(memo, -1, sizeof(memo));
        
        return recursionWithMemoization(m, n, maxMove, startRow, startColumn);
    }
private:
//     int recursive(int m, int n, int maxMove, int startR, int startC){
//         if(startR>=m or startR<0 or startC>=n or startC<0) return 1;
//         if(maxMove<=0) return 0;
        
//         return (
//             (recursive(m, n, maxMove-1, startR+1, startC)%mod) + 
//             (recursive(m, n, maxMove-1, startR, startC-1)%mod) + 
//             (recursive(m, n, maxMove-1, startR-1, startC)%mod) + 
//             (recursive(m, n, maxMove-1, startR, startC+1)%mod)
//         )%mod;
//     }
    
    int recursionWithMemoization(int m, int n, int maxMove, int startRow, int startColumn){
        
        if(startRow>=m or startRow<0 or startColumn>=n or startColumn<0) return 1;
        if(maxMove<=0) return 0;
        if(memo[startRow][startColumn][maxMove]!=-1) return memo[startRow][startColumn][maxMove];
        
        memo[startRow][startColumn][maxMove] = (
            (recursionWithMemoization(m, n, maxMove-1, startRow+1, startColumn)%mod) + 
            (recursionWithMemoization(m, n, maxMove-1, startRow, startColumn-1)%mod) + 
            (recursionWithMemoization(m, n, maxMove-1, startRow-1, startColumn)%mod) + 
            (recursionWithMemoization(m, n, maxMove-1, startRow, startColumn+1)%mod)
        )%mod;
        
        return memo[startRow][startColumn][maxMove];
    }
};
