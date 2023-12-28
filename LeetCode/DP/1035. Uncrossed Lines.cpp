// 1035. Uncrossed Lines
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int idx1 = 0, idx2 = 0;

        //recursive: TLE
        // recursive(idx1, idx2, nums1, nums2);

        //recursion with memoization
        // vector<vector<int>> memo(nums1.size(), vector<int> (nums2.size(), -1));
        // recursionWithMemo(0, 0, nums1, nums2, memo);

        // return mx;

        //tabulation
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
private:
    int mx = 0;    
    int recursive(int idx1, int idx2, vector<int> &nums1, vector<int> &nums2){
        
        if(idx1>=nums1.size() or idx2>=nums2.size()) return 0;

        int taken = 0, notTaken = 0;
        if(nums1[idx1]==nums2[idx2]){
            taken = 1+recursive(idx1+1, idx2+1, nums1, nums2);
        }
        notTaken = max(recursive(idx1, idx2+1, nums1, nums2), recursive(idx1+1, idx2, nums1, nums2));
        mx = max(taken, notTaken);
        return mx;
    }
    int recursionWithMemo(int idx1, int idx2, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &memo){
        if(idx1>=nums1.size() or idx2>=nums2.size()) return 0;
        if(memo[idx1][idx2]!=-1) return memo[idx1][idx2];

        int taken = 0, notTaken = 0;
        if(nums1[idx1]==nums2[idx2]){
            taken = 1+recursionWithMemo(idx1+1, idx2+1, nums1, nums2, memo);
        }
        notTaken = max(recursionWithMemo(idx1+1, idx2, nums1, nums2, memo), recursionWithMemo(idx1, idx2+1, nums1, nums2, memo));
        memo[idx1][idx2] = mx = max(taken, notTaken);
        return mx;
    }
};