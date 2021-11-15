class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int product = prices[0];
        for(int i=1;i<prices.size();i++){
            
            if(prices[i]>product){
                profit+=(prices[i]-product);
                product = prices[i];
            }
            else if(prices[i]<product){
                product = prices[i];
            }
        }
        
        
        return profit;
    }
};
