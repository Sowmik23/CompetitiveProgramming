class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> res;
        vector<int> tmp;
        
        backTrack(k, n, res, tmp, 0, 0, 1);
        
        return res;
    }
private:
    void backTrack(int k, int n, vector<vector<int>> &res, vector<int> &tmp, int sum, int cnt, int pos){
        if(sum>n) return;
        if(sum==n and cnt==k){
            // cout<<cnt<<" :cnt"<<endl;
            res.push_back(tmp);
            return;
        }
        for(int i=pos;i<=9;i++){
            tmp.push_back(i);
            backTrack(k, n, res, tmp, sum+i, cnt+1, i+1);
            tmp.pop_back();
        }
    }
};
