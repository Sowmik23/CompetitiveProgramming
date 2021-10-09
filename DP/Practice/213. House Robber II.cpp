class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        return max(dp(0, n-2, nums), dp(1, n-1, nums));
    }
private:
    int dp(int i, int n, vector<int> &nums){
        
        int memo_i, memo_i_1 = 0, memo_i_2 = 0;
        
        for(int j = i;j<=n;j++){ 
            memo_i = max(memo_i_1, nums[j]+memo_i_2);
            memo_i_2 = memo_i_1;
            memo_i_1 = memo_i;
        }
        return memo_i;
    }
};
