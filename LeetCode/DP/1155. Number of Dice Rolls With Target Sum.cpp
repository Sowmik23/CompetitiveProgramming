// 1155. Number of Dice Rolls With Target Sum

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        
        //dynamic programming: 0-1 knapsack

        //recursive
        // return recursive(n, k, target, k);

        //recursive with memoization
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>> (k+1, vector<int> (target+1, -1)));
        return recursionWithMemo(memo, n, k, target, k)%mod;
    }
private:
    const int mod = 1e9+7;
    int recursive(int n, int k, int target, int dice){
        if(n==0){
            if(target==0) return 1;
            else return 0;
        }

        if(dice<=0) return 0;

        int taken = 0, notTaken = 0;
        if(dice<=target) taken = recursive(n-1, k, target-dice, k)%mod;
        notTaken = recursive(n, k, target, dice-1)%mod;
        return (taken+notTaken)%mod;
    }

    int recursionWithMemo(vector<vector<vector<int>>> &memo, int n, int k, int target, int dice){
        if(n==0){
            if(target==0) return 1;
            else return 0;
        }
        if(dice<=0) return 0;
        if(memo[n][k][target]!=-1) return memo[n][k][target]%mod;

        int taken = 0, notTaken = 0;
        if(dice<=target) taken = recursionWithMemo(memo, n-1, k, target-dice, k)%mod;
        notTaken = recursionWithMemo(memo, n, k, target, dice-1)%mod;

        return memo[n][k][target] = (taken + notTaken)%mod;
    }
};