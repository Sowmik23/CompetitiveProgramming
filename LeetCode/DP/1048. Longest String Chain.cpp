class Solution {
public:
    unordered_map<string, int> mp;
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        if(n<=1) return n;
                
        sort(words.begin(), words.end());
        
        for(int i=0;i<n;i++){
            mp[words[i]] = i;
        }
        
       // return dp(words, mp, words[words.size()-1], words.size()-1));
    
        int res = 1;
        vector<int> memo(n, -1);
        
        for(int i=n-1;i>=0;i--){
            if(memo[i]==-1){
                res = max(res, dp(words, memo, i));
            }    
        }
        return res;
    }
    
private:
    /*
    int dp(vector<string>&words, unordered_map<string, bool> &mp, string str, int i){
        if(i<0) return 0;
        
        int x= 0, y = 0;
        
        for(int j=0;j<str.size();j++){
            string s = str;
            s.erase(j, 1);
            if(j<str.size()-1){
                if(mp[s]) {
                    x = 1+dp(words, mp, s, i);
                }
                //else x = dp(words, mp, i);
            }
            else if(j==str.size()-1) {
                if(mp[s]) y = 1+dp(words, mp, s, i);
                else y = dp(words, mp, "", i-1);
            }
        }
        return max(x, y);
    }
    */
    int dp(vector<string> &words, vector<int> &memo, int i){
        if(memo[i]!=-1) return memo[i];
        int ans = 1;
        for(int j=0;j<words[i].size();j++){
            string str = words[i];
            str.erase(str.begin()+j);               
            if(mp.find(str)!=mp.end()) ans = max(ans, 1+dp(words, memo, mp[str]));
        }
        
        return memo[i] = ans;
    }
};
