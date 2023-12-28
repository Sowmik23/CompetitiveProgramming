class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        //recursive
        //return recursive(costs, coins, costs.size());

        //recursion with memoization
        // vector<vector<int>> memo(costs.size()+1, vector<int> (coins+1, -1));
        // return recursiveWithMemo(costs, memo, coins, costs.size());


        //as maximum coins can be 1e8 so it will be memory limit exit
        //so need to apply greedy approach

        //firs sort : O(nlogn)
        sort(costs.begin(), costs.end());
        int mx = 0;
        for(int i=0;i<costs.size();i++){
            if(coins>=costs[i]){
                coins-=costs[i];
                mx++;
            }
            else break;
        }
        return mx;
    }
private:
    int recursive(vector<int> &costs, int coins, int i){
        if(i==0) return 0;

        if(coins==0) return 0;
        if(costs[i-1]>coins) return recursive(costs, coins, i-1);
        return max(1+recursive(costs, coins-costs[i-1], i-1), recursive(costs, coins, i-1));
    }
    int recursiveWithMemo(vector<int> &costs, vector<vector<int>>&memo, int coins, int i){
        if(i==0) return 0;
        if(coins==0) return 0;
        if(memo[i][coins]!=-1) return memo[i][coins];

        if(costs[i-1]>coins) return recursiveWithMemo(costs, memo, coins, i-1);
        return memo[i][coins] = max(1+recursiveWithMemo(costs, memo, coins-costs[i-1], i-1), recursiveWithMemo(costs, memo, coins, i-1));
    }
};
