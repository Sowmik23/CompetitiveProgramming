class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        //Dynamic Programming: After sorting find out longest increasing subsequence

        int n = scores.size();
        vector<vector<int>> nums(n);
        for(int i=0;i<n;i++){
            nums[i].push_back(ages[i]);
            nums[i].push_back(scores[i]);
        }
        sort(nums.begin(), nums.end());
        //for(auto n: nums) cout<<n[0]<<" "<<n[1]<<endl;

        //recursive: TLE
        // return recursive(nums, 0, INT_MIN, 0);

        //recursion with memoization
        vector<vector<int>> memo(n+1, vector<int> (n+2, -1));
        return recursionWithMemo(nums, memo, 0, -1);
    }
private:
    int recursionWithMemo(vector<vector<int>>& nums, vector<vector<int>>& memo, int i, int prev){
        if(i>=nums.size()) return 0;
        if(memo[i][prev+1]!=-1) return memo[i][prev+1];

        int taken = INT_MIN;
        if(prev==-1 or nums[i][1]>=nums[prev][1]) taken = nums[i][1]+recursionWithMemo(nums, memo, i+1, i);
        int notTaken = recursionWithMemo(nums, memo, i+1, prev);

        return memo[i][prev+1] = max(taken, notTaken);
    }
    int recursive(vector<vector<int>>& nums, int i, int prev, int sum){
        if(i>=nums.size()) return sum;

        int taken = sum;
        if(nums[i][1]>=prev) taken = recursive(nums, i+1, nums[i][1], sum+nums[i][1]);
        int notTaken = recursive(nums, i+1, prev, sum);

        return max(taken, notTaken);
    }
};
