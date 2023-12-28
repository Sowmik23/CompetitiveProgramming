class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> res;
        vector<int> tmp;

        backTrack(res, tmp, k, n, 1, 0, 0);

        return res;
    }
private:
    void backTrack(vector<vector<int>> &res, vector<int> &tmp, int k, int n, int idx, int sum, int cnt){
        if(sum>n or cnt>k) return;

        if(sum==n and cnt==k){
            res.push_back(tmp);
            return;
        }
        for(int i=idx;i<=9;i++){
            tmp.push_back(i);
            backTrack(res, tmp, k, n, i+1, sum+i, cnt+1);
            tmp.pop_back();
        }
        return;
    }
};
