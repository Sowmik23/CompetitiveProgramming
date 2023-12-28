class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];
        //recursive
        // return max(recursive(nums, nums.size(), 1), recursive(nums, nums.size()-1, 0));

        //recursionWithMemo
//         vector<int> memo(nums.size()+1, -1);
//         int x = recursionWithMemo(nums, memo, nums.size(), 1);
//         memo = vector<int> (nums.size()+1, -1);
//         int y = recursionWithMemo(nums, memo, nums.size()-1, 0);

//         return max(x, y);

        //tabulation
        int x = tabulation(nums, 0, nums.size()-2);
        int y = tabulation(nums, 1, nums.size()-1);
        //cout<<x<<" "<<y<<endl;

        return max(x, y);
    }
private:
    int recursive(vector<int> &nums, int i, int mn){
        if(i<=mn) return 0;
        return max(recursive(nums, i-2, mn)+nums[i-1], recursive(nums, i-1, mn));
    }
    int recursionWithMemo(vector<int> &nums, vector<int> &memo, int i, int mn){
        if(i<=mn) return 0;
        if(memo[i]!=-1) return memo[i];

        return memo[i] = max(recursionWithMemo(nums, memo, i-2, mn)+nums[i-1], recursionWithMemo(nums, memo, i-1, mn));
    }
    int tabulation(vector<int> &nums, int start, int end){
        vector<int> dp;
        for(int i=start;i<=end;i++){
            if(i==start) dp.push_back(nums[i]);
            else if(i==start+1) dp.push_back(max(nums[i], nums[start]));
            else dp.push_back(max(dp[dp.size()-1], dp[dp.size()-2]+nums[i]));
        }
        return dp[dp.size()-1];
    }
};
