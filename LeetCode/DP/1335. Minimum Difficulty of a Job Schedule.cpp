class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {


        //split the array(size n) into d numbers and minimize the sum of max of each part.
        //DP


        int n = jobDifficulty.size();
        //base cases
        if(d>jobDifficulty.size()) return -1;

        //recursive
        //return recursive(jobDifficulty, n, d, 0);

        //recursion with memoization
        vector<vector<int>> memo(n+1, vector<int> (d+1, -1));
        return recursionWithMemo(jobDifficulty, memo, n, d, 0);
    }
private:
    int recursive(vector<int> &jobDifficulty, int n, int d, int i){

        //base case
        if(d==1){
            int mx = jobDifficulty[i];
            for(int j=i+1;j<n;j++) mx = max(mx, jobDifficulty[j]);
            return mx;
        }

        int mx = INT_MIN;
        int res = INT_MAX;
        for(int j=i;j<n-d+1;j++){
            mx = max(mx, jobDifficulty[j]);
            res = min(res, mx+recursive(jobDifficulty, n, d-1, j+1));
        }
        return res;
    }

    int recursionWithMemo(vector<int> &jobDifficulty, vector<vector<int>>&memo, int n, int d, int i){
        if(d==1){
            int mx = jobDifficulty[i];
            for(int j=i+1;j<n;j++) mx = max(mx, jobDifficulty[j]);
            return mx;
        }

        if(memo[i][d]!=-1) return memo[i][d];

        int mx=INT_MIN;
        int res=INT_MAX;
        for(int j=i;j<n-d+1;j++){
            mx = max(mx, jobDifficulty[j]);
            res = min(res, mx+recursionWithMemo(jobDifficulty, memo, n, d-1, j+1));
        }

        return memo[i][d]=res;
    }
};
