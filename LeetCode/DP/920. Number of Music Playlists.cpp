// 920. Number of Music Playlists
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        

        //recursive: TLE
        //Time: O(2^n)
        //recursion
        // return recursive(n, goal, k, n);

        //recurion with memoization
        vector<vector<int>> memo(n+1, vector<int> (goal+1, -1));
        return recursionWithMemo(memo, n, k, goal, n);
    }
private:
    const int mod = 1e9+7;
    int recursive(int n, int goal, int k, int i){
        if(i==0 and goal==0) return 1;
        if(i==0 or goal==0) return 0;

        long res = 0;
        res = (long) recursive(n, goal-1, k, i-1)*(n-i+1)%mod;
        if(i>k) res+= (long) recursive(n, goal-1, k, i)*(i-k)%mod;
        return res%mod;
    }
    long recursionWithMemo(vector<vector<int>> &memo, int n, int k, int goal, int i){
        if(i==0 and goal==0) return 1;
        if(i==0 or goal==0) return 0;
        if(memo[i][goal]!=-1) return memo[i][goal];

        long res = 0;
        res = (long long)recursionWithMemo(memo, n, k, goal-1, i-1)*(n-i+1)%mod;
        if(i>k) res+= (long long)recursionWithMemo(memo, n, k, goal-1, i)*(i-k)%mod;
        return memo[i][goal] = res%mod;
    }
};