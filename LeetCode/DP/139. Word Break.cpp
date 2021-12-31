class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, bool> mp;
        for(auto& s: wordDict){
            mp[s] = true;
        }
        vector<int> memo(s.size()+1, -1);
        
        return dp(s, memo, mp, 0);
    }
private:
    bool dp(string &s, vector<int>& memo, unordered_map<string, bool> &mp, int i){
        
        if(i>s.size()) return false;
        if(i==s.size()) return true;
        
        if(memo[i]!=-1) return memo[i];
        
        string tmp;
        for(int j=i;j<s.size();j++){
            tmp.push_back(s[j]);
            if(mp[tmp]==true and dp(s, memo, mp, j+1)){
                return memo[i] = 1;
                //return true;       
            }
        }
        
        return memo[i]= 0;
    }
};
