class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {

     //using greedy method
     /*
        long long total_cst = 0;
        long long cost = 0;
        long long cashback = 0;

        for(auto& transaction : transactions){
            if(transaction[0]>transaction[1]){ //when cost is greater than cashback
                total_cst+=(transaction[0]-transaction[1]);
                cashback = transaction[1]>cashback ? transaction[1] : cashback; //update max cashback
            }
            else {
                cost = transaction[0]>cost ? transaction[0] : cost; //update max cost
            }
        }
        return total_cst + max(cost, cashback);
    */

    //using sorting    \ downs are cost and up's are cashback
                    //  \ /\
                    //      \  /
                    //       \/

        sort(transactions.begin(), transactions.end(),  [](auto& a, auto& b){
            int dip1 = min(-a[0], -a[0]+a[1]-b[0]);
            int dip2 = min(-b[0], -b[0]+b[1]-a[0]);
            if(dip1!=dip2) return dip1<dip2;
            return a[0]>b[0];
        });

        long long cost = 0;
        long long minCost = 0;
        for(int i=0;i<transactions.size();i++){
            cost -= transactions[i][0];
            minCost = min(minCost, cost);
            cost += transactions[i][1];
        }
        return abs(minCost);
    }
};
