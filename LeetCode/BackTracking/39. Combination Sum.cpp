class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        
        vector<vector<int>> res;
        vector<int> tmp;
        
        backTrack(candidates, res, tmp, 0, 0, target);
        
        return res;
    }
private:
    void backTrack(vector<int> &candidates, vector<vector<int>> &res, vector<int> &tmp, int sum, int pos, int target){
        if(sum>target) return;
        if(sum==target){
            res.push_back(tmp);
            return;
        }
        for(int i=pos;i<candidates.size();i++){
            tmp.push_back(candidates[i]);
            backTrack(candidates, res, tmp, sum+candidates[i], pos, target);
            tmp.pop_back();
            pos++;
        }
    }
};

/*

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
*/
