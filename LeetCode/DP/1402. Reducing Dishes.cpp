// 1402. Reducing Dishes
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        //recursion
        // return recursive(satisfaction, 1, 1, n);

        //recursion with memoization
        vector<vector<int>> memo(n+1, vector<int> (n+1, -1));
        return recursionWithMemo(satisfaction, memo, 1, 1, n);
    }
private:
    int recursive(vector<int> &satisfaction, int idx, int time, int n){
        if(idx>n) return 0;

        int taken = 0, notTaken = 0;
        taken = recursive(satisfaction, idx+1, time+1, n)+ (satisfaction[idx-1]*time);
        notTaken = recursive(satisfaction, idx+1, time, n);
        return max(taken, notTaken);
    }
    int recursionWithMemo(vector<int> &satisfaction, vector<vector<int>> &memo, int idx, int time, int n){
        if(idx>n) return 0;
        if(memo[idx][time]!=-1) return memo[idx][time];

        int taken = 0, notTaken = 0;
        taken = recursionWithMemo(satisfaction, memo, idx+1, time+1, n)+(satisfaction[idx-1]*time);
        notTaken = recursionWithMemo(satisfaction, memo, idx+1, time, n);
        return memo[idx][time] = max(taken, notTaken);
    }
};