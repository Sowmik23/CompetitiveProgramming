class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
 
        permutation(nums, res, 0);
        
        return res;
    }
private:
    void permutation(vector<int> &nums, vector<vector<int>> &res, int index){
        if(index==nums.size()){
            res.push_back(nums);
        }
        else{
            for(int i=index;i<nums.size();i++){
                if(i>index and nums[i]==nums[index]) continue;
                swap(nums[i], nums[index]);
                permutation(nums, res, index+1);
            }   
            
            //restore nums
            for(int i=nums.size()-1;i>index;i--){
                swap(nums[i], nums[index]);
            }
        }
    }
};
