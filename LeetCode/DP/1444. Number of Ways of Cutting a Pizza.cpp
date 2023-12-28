// 1444. Number of Ways of Cutting a Pizza
class Solution {
public:
    int ways(vector<string>& pizza, int k) {

        const int MOD = 1e9+7;
        
        int m = pizza.size();
        int n = pizza[0].size();

        vector dp(k+1, vector (m+1, vector<int> (n+1)));
        vector apples(m+1, vector<int> (n+1));

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                apples[i][j] = (pizza[i][j]=='A') + apples[i+1][j] + apples[i][j+1] - apples[i+1][j+1];
                dp[0][i][j] = apples[i][j]>0;
            }
        }

        for(int remain = 1;remain<k;remain++){
            for(int i = 0;i<m;i++){
                for(int j=0;j<n;j++){
                    for(int next_row = i+1;next_row<m;next_row++){
                        if(apples[i][j]-apples[next_row][j]>0){
                            dp[remain-1][next_row][j] = dp[remain-1][next_row][j]%MOD;
                            dp[remain][i][j] += dp[remain-1][next_row][j]%MOD;
                            dp[remain][i][j] = dp[remain][i][j]%MOD;
                        }
                    }
                    for(int next_col = j+1;next_col<n;next_col++){
                        if(apples[i][j]-apples[i][next_col]>0){
                            dp[remain-1][i][next_col] = dp[remain-1][i][next_col]%MOD;
                            dp[remain][i][j] += dp[remain-1][i][next_col];
                            dp[remain][i][j] = dp[remain][i][j]%MOD;
                        }
                    }
                }
            }
        }
        return dp[k-1][0][0]%MOD;
    }
};