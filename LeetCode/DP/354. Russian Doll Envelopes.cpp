class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        //recursion: TLE
        //sort(envelopes.begin(), envelopes.end());
        //return dp(envelopes, -1, 0);
        
        
        //recursion with memoization:TLE
        //sort(envelopes.begin(), envelopes.end());
       // vector<vector<int>> memo(envelopes.size(), vector<int> (envelopes.size(), -1));
       // return recursionWithMemo(envelopes, memo, -1, 0);
        
        
        //tabulation
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        for(int i=0;i<envelopes.size();i++){
            for(int j=0;j<i;j++){
                if(envelopes[j][0]<envelopes[i][0] and envelopes[j][1]<envelopes[i][1]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());        
    }
private:
    int dp(vector<vector<int>> &envelopes, int prev, int curr){
        if(curr>=envelopes.size()) return 0;
        
        int taken = 0;
        int notTaken = 0;
        if(prev==-1 or (envelopes[curr][0]>envelopes[prev][0] and envelopes[curr][1]>envelopes[prev][1])){
            taken = 1+dp(envelopes, curr, curr+1);
        }
        notTaken = dp(envelopes, prev, curr+1);
                                                         
        return max(taken, notTaken);
    }
    
    int recursionWithMemo(vector<vector<int>> &envelopes, vector<vector<int>> &memo, int prev, int curr){
        if(curr>=envelopes.size()) return 0;
        
        if(memo[prev+1][curr]!=-1) return memo[prev+1][curr];
        int taken = 0;
        int notTaken = 0;
        if(prev==-1 or (envelopes[prev][0]<envelopes[curr][0] and envelopes[prev][1]<envelopes[curr][1])){
            taken = 1+recursionWithMemo(envelopes, memo, curr, curr+1);
        }
        notTaken = recursionWithMemo(envelopes, memo, prev, curr+1);
        
        return memo[prev+1][curr] = max(taken, notTaken);
    }
};
