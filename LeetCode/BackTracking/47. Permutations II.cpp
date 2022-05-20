class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        backTrack(nums, res, 0, nums.size()-1);
        
        return res;
    }
private:
    set<vector<int>> st;
    void backTrack(vector<int> &nums, vector<vector<int>> &res, int start, int end){
        if(start==end){
            if(st.count(nums)!=0) return;
            res.push_back(nums);
            st.insert(nums);
            return;
        }
        for(int i=start;i<=end;i++){
            swap(nums[i], nums[start]);
            backTrack(nums, res, start+1, end);
            swap(nums[i], nums[start]);
        }
    }
};
