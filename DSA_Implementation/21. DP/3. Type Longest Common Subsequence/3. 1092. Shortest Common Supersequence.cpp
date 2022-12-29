class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        //LCS problem
        //result string = str1+str2-LCS

        //Time: O(m*n)

        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string res = "";
        int i = m, j = n;
        while(i>0 and j>0){
            if(str1[i-1]==str2[j-1]) {
                res = str1[i-1]+res;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) {
                res = str1[i-1]+res;
                i--;
            }
            else {
                res = str2[j-1]+res;
                j--;
            }
        }
        while(i>0){
            res = str1[i-1]+res;
            i--;
        }
        while(j>0){
            res = str2[j-1]+res;
            j--;
        }
        return res;
    }
private:
    bool aContainsb(string str1, string str2, int i, int j, int cnt){
        if(i==0 and j==0) {
            if(cnt==str2.size()) return true;
            return false;
        }
        if(i==0 or j==0) return false;

        if(str1[i-1]==str2[j-1]) return aContainsb(str1, str2, i-1, j-1, cnt+1);
        return (aContainsb(str1, str2, i-1, j, cnt) or aContainsb(str1, str2, i, j-1, cnt));
    }
};
