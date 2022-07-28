class Solution {
public:
    
    //TODO:
    
    
    long long mod = 1e9+7;
   // int memo[1001][1001] = {0};
    
    int kInversePairs(int n, int k) {
        
        //recursive
        //return recursive(n, k);
        
        
        //iterative
       // int memo[n+1][k+1]; // = {1};
//         for(int N=1;N<=n;N++){
//             for(int K=0;K<=k;K++){
//                 if(K==0) memo[N][K]=1;
//                 else {
//                     for(int i=0;i<=min(K, N-1);i++){
//                         memo[N][K] = (memo[N][K]+memo[N-1][K-i])%mod;
//                     }   
//                 }
//             }
//         }
        
//         return memo[n][k];
        
        vector<int> dp(k+1, 0);
        int modu = 1e9+7;
        for(int i=1; i<=n; i++){
            vector<int> temp(k+1, 0);
            temp[0] = 1;
            for(int j =1; j<=k; j++){
                long long value = (dp[j] + modu - ((j-i) >=0 ? dp[j-i] : 0))%modu;
                temp[j] = (temp[j-1] + value)%modu;
            }
            dp = temp;
        }
        return (dp[k] + modu - (k>0 ? dp[k-1] : 0))%modu;
    }
private:
//     int recursive(int n, int k){
//         if(k<=0) return k==0;
//         if(memo[n][k]==0){
//             memo[n][k] = 1;
//             for(int i=0;i<n;i++){
//                 memo[n][k] = (memo[n][k] + recursive(n-1, k-i))%mod;
//             }
//         }
        
//         return memo[n][k]-1;
//     }
};
