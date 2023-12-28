
//https://leetcode.com/problems/combination-sum-iv/discuss/85120/C%2B%2B-template-for-ALL-Combination-Problem-Set

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        //Backtracking
        //Time Complexity: O(2^target)

        vector<vector<int>> res;
        vector<int> tmp;

        backTrack(candidates, res, tmp, target, 0, 0);

        return res;
    }
private:
    void backTrack(vector<int> &candidates, vector<vector<int>> &res, vector<int> &tmp, int target, int idx, int sum){
        if(sum>target) return;
        if(sum==target){
            res.push_back(tmp);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            tmp.push_back(candidates[i]);
            backTrack(candidates, res, tmp, target, i, sum+candidates[i]);
            tmp.pop_back();
        }
    }
};
