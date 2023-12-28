// 837. New 21 Game
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        vector<double> dp(n+1);
        dp[0] = 1;
        double sum = k>0 ? 1 : 0;

        for(int i=1;i<=n;i++){
            dp[i] = sum/maxPts;
            if(i<k) sum+=dp[i];
            if(i-maxPts>=0 and i-maxPts<k){
                sum-=dp[i-maxPts];
            }
        }
        double res = 0.0;
        for(int i=k;i<=n;i++){
            res+=dp[i];
        }
        return res;
    }
};