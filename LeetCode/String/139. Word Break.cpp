class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        //dynamic programming
        set<string> st(wordDict.begin(), wordDict.end());

        //recursive: TLE
        // return dp(s, st, 0);

        //recursionWithMemo
        vector<int> memo(s.size()+1, -1);
        return recursionWithMemo(s, st, memo, 0);
    }
private:
    bool dp(string s, set<string> &st, int i){

        if(i==s.size()) return true;
        if(i>s.size()) return false;

        string tmp="";
        for(int j=i;j<s.size();j++){
            tmp+=s[j];
            if(st.count(tmp)>0 and dp(s, st, j+1)) return true;
        }
        return false;
    }
    bool recursionWithMemo(string s, set<string> &st, vector<int> &memo, int i){
        if(i==s.size()) return true;
        if(i>s.size()) return false;
        if(memo[i]!=-1) return memo[i];

        string tmp = "";
        for(int j=i;j<s.size();j++){
            tmp+=s[j];
            if(st.count(tmp)>0 and recursionWithMemo(s, st, memo, j+1)) return memo[i] = 1;
        }
        return  memo[i] = 0;
    }
};
