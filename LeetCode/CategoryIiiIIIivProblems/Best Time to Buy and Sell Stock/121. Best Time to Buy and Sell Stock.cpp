class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mn = INT_MAX;
        int mx = INT_MIN;

        for(auto& p: prices){
            mn = min(mn, p);
            mx = max(mx, p-mn);
        }

        return mx;
    }
};
