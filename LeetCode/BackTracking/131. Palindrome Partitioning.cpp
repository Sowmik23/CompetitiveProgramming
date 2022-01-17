class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res; 
        vector<string> tmp;
        
        split(s, 0, res, tmp);
        
        return res;
    }
private:
    void split(string s, int start, vector<vector<string>> &res, vector<string> &tmp){
    
        if(start==s.size()){
            res.push_back(tmp);
        }
        else {
            for(int i=start;i<s.size();i++){
                if(isPalindrom(s, start, i)){
                    tmp.push_back(s.substr(start, i-start+1));
                    split(s, i+1, res, tmp);
                    tmp.pop_back();
                }
            }
        }
    }
    
    bool isPalindrom(string &s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
