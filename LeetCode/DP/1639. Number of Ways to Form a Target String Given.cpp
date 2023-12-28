// 1639. Number of Ways to Form a Target String Given a Dictionary
class Solution {
public:
    int numWays(vector<string>& words, string target) {

        const int alphabet = 26;
        const int mod = 1e9+7;
        int m = target.size();
        int k = words[0].size();
        vector cnt(alphabet, vector<int> (k));

        for(int j=0;j<k;j++){
            for(const string& word: words){
                cnt[word[j]-'a'][j]++;
            }
        }
        vector memo(m+1, vector<long long>(k+1, -1));

        function<long long(int, int)> f = [&](int i, int j) -> long long {
            if(j==0) return i==0 ? 1 : 0;
            if(memo[i][j]!=-1) return memo[i][j];

            memo[i][j] = f(i, j-1);
            if(i>0){
                memo[i][j] +=cnt[target[i-1]-'a'][j-1]*f(i-1, j-1);
            }
            memo[i][j]%=mod;
            return memo[i][j];
        };
        return f(m, k);
    }
};