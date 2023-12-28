class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        set<vector<int>> st;
        vector<int> tmp;

        backTrack(nums, st, tmp, 0);
        return vector(st.begin(), st.end());
    }
private:
    void backTrack(vector<int> &nums, set<vector<int>> &st, vector<int> &tmp, int idx){
        if(idx==nums.size()){
            if(tmp.size()>=2) st.insert(tmp);
            return;
        }
        if(tmp.empty() or nums[idx]>=tmp.back()){
            tmp.push_back(nums[idx]);
            backTrack(nums, st, tmp, idx+1);
            tmp.pop_back();
        }
        backTrack(nums, st, tmp, idx+1);
    }
};
