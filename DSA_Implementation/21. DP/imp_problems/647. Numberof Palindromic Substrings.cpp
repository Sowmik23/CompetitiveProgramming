class Solution {
public:
    int countSubstrings(string s) {
        
        
        ///Method: DP: determine number of palindromic substring
        ///Also determine number of palindromic substring
        vector<vector<bool>> dp(s.size()+1, vector<bool> (s.size()+1, false));
        
        for(int i=0;i<s.size();i++){
            dp[i][i] = true;
            if(i+1>=s.size()) break;
            dp[i][i+1] = (s[i]==s[i+1]);
        }
        
        for(int i=s.size()-3;i>=0;i--){
            for(int j=i+2;j<s.size();j++){
                dp[i][j] = (dp[i+1][j-1] and s[i]==s[j]);
            }
        }
        
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            
            for(int j=i;j<s.size();j++){
                if(dp[i][j]==true) cnt++;
            }
        }
        
        
        return cnt;
    }
};
