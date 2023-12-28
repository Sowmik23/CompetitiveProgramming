class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //Single Number II : read-first;

        int oneBuyOneSell = 0;
        int twoBuyTwoSell = 0;
        int oneBuy = INT_MAX;
        int twoBuy = INT_MAX;

        for(int i=0;i<prices.size();i++){
            oneBuy = min(oneBuy, prices[i]);
            oneBuyOneSell = max(oneBuyOneSell, prices[i]-oneBuy);
            twoBuy = min(twoBuy, prices[i]-oneBuyOneSell);
            twoBuyTwoSell = max(twoBuyTwoSell, prices[i]-twoBuy);
        }

        return twoBuyTwoSell;
    }
};
