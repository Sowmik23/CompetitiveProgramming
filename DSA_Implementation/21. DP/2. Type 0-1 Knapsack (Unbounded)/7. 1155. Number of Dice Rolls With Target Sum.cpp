class Solution {
public:
    const int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {

        //recursion: TLE
        //return recursive(n, k, target, k);

        //recursion With Memo: Accepted
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>> (k+1, vector<int> (target+1, -1)));
        return recursionWithMemo(memo, n, k, target, k);

    }
private:
    int recursive(int n, int k, int target, int kk){
        if(n==0){
            if(target==0) return 1;
            else return 0;
        }
        if(kk<=0) return 0;

        int taken = 0, notTaken = 0;
        if(kk<=target) taken = recursive(n-1, k, target-kk, k)%mod;
        notTaken = recursive(n, k, target, kk-1)%mod;

        return (taken+notTaken)%mod;
    }

    int recursionWithMemo(vector<vector<vector<int>>> &memo, int n, int k, int target, int kk){
        if(n==0){
            if(target==0) return 1;
            else return 0;
        }
        if(kk<=0) return 0;

        if(memo[n][k][target]!=-1) return memo[n][k][target]%mod;

        int taken = 0, notTaken = 0;
        if(kk<=target) taken = recursionWithMemo(memo, n-1, k, target-kk, k)%mod;
        notTaken = recursionWithMemo(memo, n, k, target, kk-1)%mod;

        return memo[n][k][target] =  (taken + notTaken)%mod;
    }
};
