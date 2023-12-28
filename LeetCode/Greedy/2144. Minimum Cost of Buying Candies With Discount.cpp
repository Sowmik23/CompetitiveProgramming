// 2144. Minimum Cost of Buying Candies With Discount


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.rbegin(), cost.rend());
        int i = 0;

        int totalCost = 0;
        while(i<cost.size()){
            totalCost+=cost[i];
            i++;
            if(i<cost.size()){
                totalCost+=cost[i];
            }
            i+=2;
        }
        return totalCost;
    }
};
// 2 2 5 6 7 9