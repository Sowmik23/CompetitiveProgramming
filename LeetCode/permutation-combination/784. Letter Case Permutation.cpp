class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string s) {
        
        permutation(s, 0, s.size());
        
        return res;
    }
private:
    void permutation(string &s, int i, int n){
        if(i==n){
            res.push_back(s);
            return;
        }
        if(isLetter(s[i])){  //in case of letter
            s[i] = toupper(s[i]);
            permutation(s, i+1, n);

            s[i] = tolower(s[i]);
            permutation(s, i+1, n);
        }
        else permutation(s, i+1, n);  //in case of digit just go forward
    }
    
    bool isLetter(char ch){
        if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z')) return true;
        return false;
    }
};
