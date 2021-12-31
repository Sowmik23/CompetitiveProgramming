class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        //backtracking
        vector<string> res;
        string tmp="";
        
        backtrack(res, tmp, 0, 0, n);
        return res;
    }
private:
    void backtrack(vector<string> &res, string &tmp, int open, int close, int n){
        if(tmp.size()==2*n){
            res.push_back(tmp);
            return;
        }
        
        if(open<n){
            tmp.push_back('(');
            backtrack(res, tmp, open+1, close, n);
            tmp.pop_back();
        }
        if(close<open){
            tmp.push_back(')');
            backtrack(res, tmp, open, close+1, n);
            tmp.pop_back();
        }
    }
};
