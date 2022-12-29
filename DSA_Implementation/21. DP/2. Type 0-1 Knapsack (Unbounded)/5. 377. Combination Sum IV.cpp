// Follow Up
// If the given array contains negative numbers, it will result in an infinite-length permutation.
//
// For example, if the array nums contains positive integers A and negative integers B (where A>0, B<0), so there is A*B + (-B)*A=0. Which means 
// for any permutation whose sum of elements is equal to target, we can add target + A*B + (-B)*A=target.
//
// Therefore, as long as there is an arrangement whose sum of elements is equal to target, an arrangement of infinite length can be constructed.
//
// If negative numbers are allowed, the maximum length of permutations must be limited to avoid infinite-length permutations before the number of
// permutations can be counted.


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

       //recursion
        // return recursive(nums, target, nums.size());

        //recursion with memoization
        // vector<vector<int>> memo(nums.size()+1, vector<int> (target+1, -1));
        // return recursionWithMemo(nums, target, memo, nums.size());

        //tabulation
//         vector<vector<int>> dp(nums.size()+1, vector<int> (target+1, -1));

//         //base case:
//         for(int i=0;i<=nums.size();i++)  dp[i][0] = 1;
//         for(int i=0;i<=target;i++) dp[0][i] = 0;


//         for(int j=1;j<=target;j++){
//             for(int i=1;i<=nums.size();i++){
//                 if(nums[i-1]<=j) dp[i][j] = dp[0][j-nums[i-1]];
//                 dp[i][j] =  dp[i-1][j-nums[i-1]];
//             }
//         }
//         return dp[nums.size()-1][target];


        //tabulation: optimized memory
        vector<unsigned int> dp(target+1,  0); //unsigned int works but why don't know
        dp[0] = 1;
        for(int j=1;j<=target;j++){
            for(int i=1;i<=nums.size();i++){
                if(nums[i-1]<=j) dp[j]+=dp[j-nums[i-1]];
            }
        }
        return dp[target];
    }
private:
    int recursive(vector<int> &nums, int target, int i){
        if(target==0) return 1;
        if(i==0) return 0;

        int taken = 0, notTaken = 0;
        if(nums[i-1]<=target) taken = recursive(nums, target-nums[i-1], nums.size());  //difference is here! you need to start from the first point again
        notTaken = recursive(nums, target, i-1);

        return taken + notTaken;
    }

    int recursionWithMemo(vector<int> &nums, int target,  vector<vector<int>>&memo, int i){
        if(target==0) return 1;
        if(i==0) return 0;

        if(memo[i-1][target]!=-1) return memo[i-1][target];

        int taken = 0, notTaken = 0;
        if(nums[i-1]<=target) taken = recursionWithMemo(nums, target-nums[i-1], memo, nums.size());
        notTaken = recursionWithMemo(nums, target, memo, i-1);

        return memo[i-1][target] = taken + notTaken;
    }
};
