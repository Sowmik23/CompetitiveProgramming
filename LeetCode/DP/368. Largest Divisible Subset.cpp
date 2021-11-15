class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        //Time: O(n^2)
        
        sort(nums.begin(), nums.end());
        
        
        vector<int> dp(nums.size(), 0);
        vector<int> parent(nums.size(), 0);
        
        
        int m = 0;
        int mi = 0;
        
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i;j<nums.size();j++){

                if(nums[j]%nums[i]==0 and dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j];
                    parent[i] = j;
                    
                    if(dp[i]>m){
                        m = dp[i];
                        mi = i;
                    }
                }
            }
        }
        
        vector<int> res;
        for(int i=0;i<m;i++){
            res.push_back(nums[mi]);
            mi = parent[mi];
        }
        
        
        return res;
    }
};
