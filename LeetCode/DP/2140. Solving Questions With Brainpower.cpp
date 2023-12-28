// 2140. Solving Questions With Brainpower
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        

        int n = questions.size();
        vector<long long> memo(n, -1);
        return recursive(questions, memo, 0);
    }
private:
    long long recursive(vector<vector<int>> &questions, vector<long long> &memo, int idx){

        if(idx>=questions.size()) return 0;
        if(memo[idx]!=-1) return memo[idx];

        long long taken = 0, notTaken = 0;
        taken = questions[idx][0] + recursive(questions, memo, idx+questions[idx][1]+1);
        notTaken = recursive(questions, memo, idx+1);

        return memo[idx] = max(taken, notTaken);
    }
};