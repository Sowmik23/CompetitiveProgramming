// 983. Minimum Cost For Tickets
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        unordered_map<int, int> mp;
        for(auto& day: days) mp[day]++;

        // return recursive(1, days, costs, mp);

        //recursion with memoization
        // vector<int> memo(367);
        // return recursionWithMemo(1, days, costs, memo, mp);

        //tabulation
        vector<int> dp(365+30+1);
        for(int i=1;i<366;i++){
            dp[i] = dp[i-1];
            if(mp.find(i)!=mp.end()){
                dp[i] = min({dp[max(0, i-1)]+costs[0], dp[max(0, i-7)]+costs[1], dp[max(0, i-30)]+costs[2]});
            }
        }
        return dp[365];
    }
private:
    int recursive(int d, vector<int> &days, vector<int> &costs, unordered_map<int, int> mp){
        if(d>365) return 0;

        int res;
        if(mp.find(d)!=mp.end()){
            res = min({recursive(d+1, days, costs, mp)+costs[0], recursive(d+7, days, costs, mp)+costs[1], recursive(d+30, days, costs, mp)+costs[2]});
        }
        else {
            res = recursive(d+1, days, costs, mp);
        }
        return res;
    }
    int recursionWithMemo(int d, vector<int> &days, vector<int> &costs, vector<int> &memo, unordered_map<int, int> &mp ){
        if(d>365) return 0;

        if(memo[d]) return memo[d];
        if(mp.find(d)!=mp.end()){
            memo[d] = min({recursionWithMemo(d+1, days, costs, memo, mp)+costs[0], recursionWithMemo(d+7, days, costs, memo, mp)+costs[1], recursionWithMemo(d+30, days, costs, memo, mp)+costs[2]});
        }
        else memo[d] = recursionWithMemo(d+1, days, costs, memo, mp);
        return memo[d];
    }
};