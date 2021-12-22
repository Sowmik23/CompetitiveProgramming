class Solution {
public:
	//https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        
        vector<int> tmp;
        backtrack(candidates, res, tmp, target, 0);
        
        return res;
    }
private:
    void backtrack(vector<int> &candidates, vector<vector<int>> &res, vector<int> &tmp, int target, int i){
        if(target<0) return;
        else if(target==0) res.push_back(tmp);
        else {
            for(int j=i;j<candidates.size();j++){
                tmp.push_back(candidates[j]);
                backtrack(candidates, res, tmp, target-candidates[j], j);
                tmp.pop_back();
            }
        }
    }
};
