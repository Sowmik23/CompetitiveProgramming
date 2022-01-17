class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        stack<int> stk;
        for(int i=0;i<prices.size();i++){
            while(!stk.empty() and prices[stk.top()]>=prices[i]){
                prices[stk.top()] = prices[stk.top()] - prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        
        return prices;
    }
};
