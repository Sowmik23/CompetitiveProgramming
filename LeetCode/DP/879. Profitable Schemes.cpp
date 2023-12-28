// 879. Profitable Schemes
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profits) {
        
        memset(memo, -1, sizeof(memo));
        return dp(profits, group, n, minProfit, 0, 0, 0);
    }
private:
    const int mod = 1e9+7;
    int memo[101][101][101];
    int dp(vector<int> &profits, vector<int> &group, int &n, int &minProfit, int idx, int cnt, int profit){
        if(idx>=group.size()) return profit>=minProfit;
        if(memo[idx][cnt][profit]!=-1) return memo[idx][cnt][profit];

        int totalWays = dp(profits, group, n, minProfit, idx+1, cnt, profit);
        if(cnt+group[idx]<=n){
            totalWays+=dp(profits, group, n, minProfit, idx+1, cnt+group[idx], min(profit+profits[idx], minProfit));
        }
        return memo[idx][cnt][profit] = totalWays%mod;
    }
};