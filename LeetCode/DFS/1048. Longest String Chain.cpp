// 1048. Longest String Chain
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        //Using Hash Map
        /*
        int n = words.size();
        unordered_map<string, int> mp;
        int mxlen = 0;

        sort(words.begin(), words.end(), [](auto& a, auto& b){
            return a.size()<b.size();
        });

        for(int i=0;i<n;i++){
            mp[words[i]] = 1; 
            for(int j=0;j<i;j++){
                if(words[i].size()-words[j].size()==1 and isPredecessor(words[j], words[i])) {
                    mp[words[i]] = max(mp[words[i]], mp[words[j]]+1);
                }
            }
            mxlen = max(mxlen, mp[words[i]]);
        }
        
        return mxlen;
        */

        //Using Dynamic Programming
        int n = words.size();
        vector<int> memo(n, -1);
        unordered_map<string, int> mp;

        //sorting decending order of words size
        sort(words.begin(), words.end(), [](auto& a, auto& b){
            return a.size()>b.size();
        });
        for(int i=0;i<words.size();i++){
            mp[words[i]] = i;
        }

        int mx = 0;
        for(int i=0;i<n;i++){
            if(memo[i]==-1){
                mx = max(mx, dfs(words, memo, mp, i));
            }
        }
        return mx;
    }
private:
    int dfs(vector<string> &words, vector<int> &memo, unordered_map<string, int> &mp, int idx){
        if(memo[idx]!=-1) return memo[idx];
        int cnt = 1;
        
        for(int i=0;i<words[idx].size();i++){
            string str = words[idx];
            str.erase(str.begin()+i);
            if(mp.find(str)!=mp.end()) cnt = max(cnt, 1+dfs(words, memo, mp, mp[str]));
        }
        return memo[idx] = cnt;
    }
    bool isPredecessor(string item, string word){
        int diff = 0;
        int i = 0, j = 0;
        while(i<item.size() and j<word.size()){
            if(item[i]==word[j]){
                i++, j++;
            }
            else {
                diff++;
                if(diff>1) return false;
                j++;
            }
        }
        return true;
    }
};