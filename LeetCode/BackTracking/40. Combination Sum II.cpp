class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        
        vector<int> tmp;
        
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, tmp, 0, 0, target);
        
        // for(auto& s: st){
        //     res.push_back(s);
        // }
        
        return res;
    }
private:
    void backTrack(vector<int> &candidates, vector<int> &tmp, int sum, int pos, int target){
        
        if(sum>target) return;
        if(sum==target){
            if(st.count(tmp)==0) {
                st.insert(tmp);
                res.push_back(tmp);
            }
            return;
        }

        for(int i=pos;i<candidates.size();i++){
            if(i>pos and candidates[i]==candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            backTrack(candidates, tmp, sum+candidates[i], i+1, target);
           // pos++;
            tmp.pop_back();
        }
    }
};


/*

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

*/
