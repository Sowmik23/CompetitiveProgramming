class Solution {
public:
    vector<string> letterCombinations(string digits) {

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> res;
        if(digits.size()==0) return res;

        string tmp="";
        backTrack(digits, mp, res, tmp, 0);
        return res;
    }
private:
    void backTrack(string &digits, unordered_map<char, string> &mp, vector<string> &res, string tmp, int idx){
        if(tmp.size()==digits.size()){
            res.push_back(tmp);
            return;
        }
        for(auto chars: mp[digits[idx]]){
            tmp.push_back(chars);
            backTrack(digits, mp, res, tmp, idx+1);
            tmp.pop_back();
        }
    }
};



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
