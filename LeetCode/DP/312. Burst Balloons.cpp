class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        //Dynamic Programming: Time: O(n^3)
        
        vector<int> numbers(nums.size()+2);
        int n = 1;
        for(auto& i: nums){
            if(i>0) {
                numbers[n] = i;
                n++;
            }
        }
        numbers[0] = numbers[n] = 1;
        n++;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int k=2;k<n;k++){
            for(int left=0;left<n-k;left++){
                int right = left+k;
                for(int i=left+1;i<right;i++){
                    dp[left][right] = max(dp[left][right], numbers[left]*numbers[i]*numbers[right]+dp[left][i]+dp[i][right]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
