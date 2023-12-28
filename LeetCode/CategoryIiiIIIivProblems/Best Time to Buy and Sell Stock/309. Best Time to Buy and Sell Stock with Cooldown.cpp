class Solution {
public:
    int maxProfit(vector<int>& prices) {

        //recursion: TLE
        // return recursive(prices, 0, 1);

        //recursion with memoization
        vector<vector<int>> memo(prices.size(), vector<int> (2, -1));
        return recursionWithMemo(prices, memo, 0, 1);
    }
private:
    int recursive(vector<int> &prices, int i, int j){
        if(i>=prices.size()) return 0;

        int x = recursive(prices, i+1, j);
        int y = 0;
        if(j) y = recursive(prices, i+1, 0)-prices[i];
        else y = recursive(prices, i+2, 1)+prices[i];

        return max(x, y);
    }
    int recursionWithMemo(vector<int> &prices, vector<vector<int>> &memo, int i, int j){
        if(i>=prices.size()) return 0;

        if(memo[i][j]!=-1) return memo[i][j];
        int x = recursionWithMemo(prices, memo, i+1, j);
        int y = 0;
        if(j) y = recursionWithMemo(prices, memo, i+1, 0)-prices[i];
        else y = recursionWithMemo(prices, memo, i+2, 1)+prices[i];

        return memo[i][j] = max(x, y);
    }
};
