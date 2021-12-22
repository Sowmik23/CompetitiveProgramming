class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, res, tmp, target, 0);
        
        return res;
    }
private:
    void backtrack(vector<int> & candidates, vector<vector<int>> &res, vector<int> &tmp, int target, int pos){
        if(target<0) return;
        else if(target==0) res.push_back(tmp);
        else {
            for(int i=pos;i<candidates.size();i++){
                if(i>pos and candidates[i]==candidates[i-1]) continue;
                tmp.push_back(candidates[i]);
                backtrack(candidates, res, tmp, target-candidates[i], i+1);
                tmp.pop_back();
            }
        }
    }
};
