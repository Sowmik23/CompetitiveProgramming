class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        
        return permutation(nums, 0, n-1);
    }
private:
    vector<vector<int>> res;
    
    vector<vector<int>> permutation(vector<int> & nums, int l, int r){
        if(l==r){
            res.push_back(nums);
        }
        else {
            for(int i=l;i<=r;i++){
                swap(nums[i], nums[l]);
                permutation(nums, l+1, r);
                swap(nums[i], nums[l]);
            }
        }
        
        return res;
    }
};
