class Solution {
public:
    vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        string tmp = "";
        if(digits.size()==0) return res;
        
        backtrack(digits, res, tmp, 0);
        
        return res;
    }
private:
    void backtrack(string digits, vector<string> &res, string &tmp, int pos){
        if(pos==digits.size()){
            res.push_back(tmp);
            return;
        }
        for(auto& chars: mp[digits[pos]-'2']){
            tmp.push_back(chars);
            backtrack(digits, res, tmp, pos+1);
            tmp.pop_back();
        }
    }
};
