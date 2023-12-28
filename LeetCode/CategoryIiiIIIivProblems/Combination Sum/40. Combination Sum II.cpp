class Solution {
public:
    set<vector<int>> st;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> tmp;

        backTrack(candidates, res, tmp, target, 0, 0);

        return res;
    }
private:
    void backTrack(vector<int> &candidates, vector<vector<int>> &res, vector<int> &tmp, int target, int idx, int sum){
        if(sum>target) return;
        if(sum==target){
            if(st.count(tmp)==0){
                res.push_back(tmp);
                st.insert(tmp);
            }
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx and candidates[i]==candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            backTrack(candidates, res, tmp, target, i+1, sum+candidates[i]);
            tmp.pop_back();
        }
        return;
    }
};
