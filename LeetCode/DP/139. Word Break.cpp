// 139. Word Break
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        //recursive: TLE
        // return recursive(s, st, 0);

        //recursion with memoization
        //Time: O(n*m*k)
        // vector<int> seen(s.size(), -1);
        // return recursionWithMemo(s, st, 0, seen);

        //tabulation
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] and st.count(s.substr(j, i-j)) ){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
private:
    bool recursive(string s, unordered_set<string> &st, int startIdx){
        if(startIdx>s.size()) return false;
        if(startIdx==s.size()) return true;

        string str="";
        for(int i=startIdx;i<s.size();i++){
            str+=s[i];
            if(st.find(str)!=st.end() and recursive(s, st, i+1)) return true;
        }
        return false;
    }
    bool recursionWithMemo(string s, unordered_set<string> &st, int startIdx, vector<int> &seen){
        if(startIdx>s.size()) return false;
        if(startIdx==s.size()) return true;

        if(seen[startIdx]!=-1) return seen[startIdx];
        string str="";
        for(int i=startIdx;i<s.size();i++){
            str+=s[i];
            if(st.find(str)!=st.end() and recursionWithMemo(s, st, i+1, seen)){
                return seen[startIdx] = 1;
            }
        }
        return seen[startIdx] = 0;
    }
};




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
