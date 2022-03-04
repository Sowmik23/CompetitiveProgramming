class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int n = accounts.size();
        int m = accounts[0].size();
        int mxWealth = 0;
        
        for(int i=0;i<n;i++){
            int wealth = 0;
            for(int j = 0;j<m;j++){
                wealth+=accounts[i][j];
            }
            mxWealth = max(mxWealth, wealth);
        }
        
        return mxWealth;
    }
};
