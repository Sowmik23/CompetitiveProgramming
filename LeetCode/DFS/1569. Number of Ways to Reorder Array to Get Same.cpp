// 1569. Number of Ways to Reorder Array to Get Same BST
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        
        m = nums.size();
        pascalTriangle = vector<vector<long>> (m+1);
        for(int i=0;i<=m;i++){
            pascalTriangle[i].resize(i+1, 1);
            for(int j=1;j<i;j++){
                pascalTriangle[i][j] = (pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j])%mod;
            }
        }
        
        return dfs(nums)-1;
    }
private:
    int m;
    int mod = 1e9+7;
    vector<vector<long>> pascalTriangle;

    long dfs(vector<int> &nums){
        if(nums.size()<3) return 1;

        vector<int> leftNodes, rightNodes;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[0]) leftNodes.push_back(nums[i]);
            else rightNodes.push_back(nums[i]);
        }

        long leftWays = dfs(leftNodes)%mod;
        long rightWays = dfs(rightNodes)%mod;
        return ((leftWays*rightWays)%mod * pascalTriangle[nums.size()-1][leftNodes.size()])%mod;
    }
};