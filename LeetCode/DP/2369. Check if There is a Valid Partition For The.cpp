// 2369. Check if There is a Valid Partition For The Array
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();

        //recursive: TLE
        //Time: O(2^n)
        // return recursive(nums, n, 0);

        //recursion with memoization
        //Time: O(n)
        // vector<int> memo(n+1, -1);
        // return recursionWithMemo(nums, memo, n, 0);

        //tabulation
        //Time: O(n)
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i=1;i<=n;i++){
            if(i-2>=0 and nums[i-1]==nums[i-2]) dp[i] = dp[i] or dp[i-2];
            if(i-3>=0 and ((nums[i-1]==nums[i-2] and nums[i-2]==nums[i-3]) or 
    (nums[i-1]-nums[i-2]==1 and nums[i-2]-nums[i-3]==1)) ){
                dp[i] = dp[i] or dp[i-3];
            }
        }
        return dp[n];
    }
private:
    bool recursive(vector<int> &nums, int n, int i){
        if(i==n) return true;
        if(i>n) return false;
        if(n-i<2) return false;

        bool a = false, b = false;
        if(i+1<n and nums[i]==nums[i+1]) a = recursive(nums, n, i+2);
        if(i+2<n and ((nums[i]==nums[i+1] and nums[i]==nums[i+2]) or 
        (nums[i+2]-nums[i+1]==1 and nums[i+1]-nums[i]==1)) ) b = recursive(nums, n, i+3);
        return a or b;
    }
    int recursionWithMemo(vector<int> &nums, vector<int> &memo, int n, int i){
        if(i==n) return true;
        if(i>n) return false;
        if(n-i<2) return false;
        if(memo[i]!=-1) return memo[i];

        bool a = false, b = false;
        if(i+1<n and nums[i]==nums[i+1]) a = recursionWithMemo(nums, memo, n, i+2);
        if(i+2<n and ((nums[i]==nums[i+1] and nums[i]==nums[i+2]) or 
        (nums[i+2]-nums[i+1]==1 and nums[i+1]-nums[i]==1)) ) b = recursionWithMemo(nums, memo, n, i+3);
        return memo[i] = a or b;
    }
};