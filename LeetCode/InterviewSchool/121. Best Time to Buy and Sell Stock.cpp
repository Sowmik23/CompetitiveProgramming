class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        ///brute force: O(n^2): TLE
      /*  int maxProfit = 0;
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                int diff = prices[j]-prices[i];
                maxProfit = max(maxProfit, diff);
            }
        }
        
        return maxProfit;
        */
        
        //approach-02: One Pass
        
        int minimum = INT_MAX;
        int maximum = 0;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i] < minimum) minimum = prices[i];
            else if(prices[i]-minimum > maximum) maximum = prices[i]-minimum;
        }
        
        return maximum;
    }
};
