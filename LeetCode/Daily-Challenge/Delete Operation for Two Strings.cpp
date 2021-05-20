class Solution {
    ///longest common subsequence problem
public:
    string word1, word2;
    int ans[1005][1005];
    int minDistance(string word1, string word2) {
        this->word1 = word1;
        this->word2 = word2;
        
        memset(ans, -1, sizeof(ans));
        
        int common = longestSubstring(word1.size()-1, word2.size()-1);
        //cout<<common<<endl;
        
        int x = word1.size();
        int y = word2.size();
        
        int ans = (x-common) + (y-common);
        
        return ans;
    }
    
    
    private:
    int longestSubstring(int a, int b){
        
        if(a<0 || b<0 ) return 0;
        if(ans[a][b]!=-1) return ans[a][b];

        if(word1[a]==word2[b])
        {
            return ans[a][b]=longestSubstring(a-1,b-1)+1;
        }
        return ans[a][b] = max(longestSubstring(a,b-1),longestSubstring(a-1,b));
    }
};
