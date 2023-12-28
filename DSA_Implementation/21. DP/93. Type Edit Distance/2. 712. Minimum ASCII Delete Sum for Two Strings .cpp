class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        //Dynamic Programming
        //Edit Distance variance

        //recursive: O(n*3^n)  n = max(s1.size(), s2.size())

        // return recursive(s1, s2, s1.size()-1, s2.size()-1);

        //recursion with memoization

        // vector<vector<int>> memo(s1.size(), vector<int> (s2.size(), -1));
        // //pass by reference, otherwise memory limit exceed
        // return recursionWithMemo(s1, s2, s1.size()-1, s2.size()-1, memo);

        //tabulation
        //Time: O(m*n)
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));

        dp[0][0] = 0;
        
        //cost when s2=="";
        for(int i=1;i<=m;i++){
            dp[i][0] = dp[i-1][0] + getASCIIValue(s1[i-1]);
        }

        //cost when s1=="";
        for(int i=1;i<=n;i++){
            dp[0][i] = dp[0][i-1] + getASCIIValue(s2[i-1]);
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    int deleteS1 = getASCIIValue(s1[i-1]) + dp[i-1][j];
                    int deleteS2 = getASCIIValue(s2[j-1]) + dp[i][j-1];
                    int deleteBoth = getASCIIValue(s1[i-1]) + getASCIIValue(s2[j-1]) + dp[i-1][j-1];
                    dp[i][j] = min({deleteS1, deleteS2, deleteBoth});
                }
            }
        }
        return dp[m][n];
    }
private:
    int recursive(string s1, string s2, int i, int j){
        if(i<0 and j<0) return 0;
        if(i<0){
            int d = 0;
            for(int idx=0;idx<=j;idx++){
                d+=getASCIIValue(s2[idx]);
            }
            return d;
        }
        if(j<0) {
            int d = 0;
            for(int idx=0;idx<=i;idx++){
                d+=getASCIIValue(s1[idx]);
            }
            return d;
        }

        if(s1[i]==s2[j]) return recursive(s1, s2, i-1, j-1);
        else {
            int a = getASCIIValue(s1[i]) + recursive(s1, s2, i-1, j);
            int b = getASCIIValue(s2[j]) + recursive(s1, s2, i, j-1);
            int c = getASCIIValue(s1[i])+getASCIIValue(s2[j]) + recursive(s1, s2, i-1, j-1);
            return min({a, b});
        }
    }
    int recursionWithMemo(string &s1, string &s2, int i, int j, vector<vector<int>> &memo){
        if(i<0 and j<0) return 0;
        if(i<0){
            int d = 0;
            for(int idx=0;idx<=j;idx++){
                d+=getASCIIValue(s2[idx]);
            }
            return d;
        }
        if(j<0){
            int d = 0;
            for(int idx=0;idx<=i;idx++){
                d+=getASCIIValue(s1[idx]);
            }
            return d;
        }
        if(memo[i][j]!=-1) return memo[i][j];

        if(s1[i]==s2[j]) return recursionWithMemo(s1, s2, i-1, j-1, memo);
        else {
            int a = getASCIIValue(s1[i]) + recursionWithMemo(s1, s2, i-1, j, memo);
            int b = getASCIIValue(s2[j]) + recursionWithMemo(s1, s2, i, j-1, memo);
            int c = getASCIIValue(s1[i]) + getASCIIValue(s2[j]) + recursionWithMemo(s1, s2, i-1, j-1, memo);
            return memo[i][j] = min({a, b, c});
        }
    }
    int getASCIIValue(char ch){
        return (int) ch;
    }
};