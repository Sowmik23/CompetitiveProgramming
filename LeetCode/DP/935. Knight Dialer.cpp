// 935. Knight Dialer

class Solution {
public:
    int knightDialer(int n) {
        

        //Dynamic programming
        //Time: O(n)

        vector<vector<int>> jumps = {
            {4, 6}, // 0-> 
            {6, 8}, // 1->
            {7, 9}, // 2->
            {4, 8}, // 3->
            {3, 9, 0}, // 4->
            {}, // 5->
            {1, 7, 0}, // 6->
            {2, 6}, // 7->
            {1, 3}, // 8->
            {2, 4} // 9->
        };

        vector<vector<int>> memo(n+1, vector<int> (10, 0));
        int res = 0;
        for(int i = 0;i<10;i++){
            res = (res + recursive(jumps, memo, n-1, i))%mod;
        }

        return res;
    }
private:
    const int mod = 1e9+7;
    int recursive(vector<vector<int>> &jumps, vector<vector<int>> &memo, int remaining, int i){
        if(remaining==0) return 1;
        if(memo[remaining][i]!=0) return memo[remaining][i];

        int res = 0;
        for(int j: jumps[i]){
            res = (res + recursive(jumps, memo, remaining-1, j))%mod;
        }
        return memo[remaining][i] = res %mod;
    }
};