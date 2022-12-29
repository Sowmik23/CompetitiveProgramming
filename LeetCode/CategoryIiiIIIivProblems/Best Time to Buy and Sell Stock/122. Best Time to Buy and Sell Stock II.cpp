class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mn = INT_MAX;
        int res=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mn){
                mn = prices[i];
            }
            else {
                res+=prices[i]-mn;
                mn = prices[i];
            }
        }
        return res;
    }
};
