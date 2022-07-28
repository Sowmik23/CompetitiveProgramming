class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        priority_queue<pair<int, int>> pq;
        vector<int> dp(n, 0);
        
        dp[n-1] = nums[n-1];
        for(int i=n-1;i>=0;i--){
            while(!pq.empty() and pq.top().second>i+k) pq.pop();
                
            if(i!=n-1){
                dp[i] +=(nums[i]+pq.top().first);
            }
            pq.push({dp[i], i});
        }
        
        return dp[0];
    }
};
