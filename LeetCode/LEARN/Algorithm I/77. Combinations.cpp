class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> tmp;
        
        combination(res, tmp, 1, n, k);
        return res;
    }
private:
    void combination(vector<vector<int>> &res, vector<int> &tmp, int l, int n, int k){
        if(tmp.size()==k) {
            res.push_back(tmp);
        }
        for(int i=l;i<=n;i++){
            tmp.push_back(i);
            combination(res, tmp, i+1, n, k);
            tmp.pop_back();
        }
    }
};
