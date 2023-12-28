// 2218. Maximum Value of K Coins From Piles
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();
        vector memo(n+1, vector<int>(k+1, -1));

        function<int(int, int)> f = [&](int i,  int coins){
            if(i==0) return 0;
            if(memo[i][coins]!=-1) return memo[i][coins];

            int currentSum = 0;
            for(int currentCoins = 0;currentCoins<=min((int)piles[i-1].size(), coins);currentCoins++){
                if(currentCoins>0){
                    currentSum+=piles[i-1][currentCoins-1];
                }
                memo[i][coins] = max(memo[i][coins], f(i-1, coins-currentCoins)+currentSum);
            }
            return memo[i][coins];
        };

        return f(n, k);
    }
};