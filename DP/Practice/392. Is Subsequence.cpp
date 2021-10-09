class Solution {
public:
    bool isSubsequence(string s, string t) {
     
        if(s.size()>t.size()) return false;
        
        
        //recursion
        //int ln = dp(0, 0, s, t);
        
        
        //recursion with memoization
        vector<vector<int>> memo(s.size()+2, vector<int> (t.size()+2, -1));
        int ln = dpWithMemoization(0, 0, s, t, memo);
        
        if(ln == s.size()) return true;
        return false;
    }
private:
    //recursion
    int dp(int i, int j, string s, string t){
        if(i>=s.size() or j>=t.size()) return 0;
        
        if(s[i]==t[j]){
            return 1+dp(i+1, j+1, s, t);
        }
        else return dp(i, j+1, s, t);
    }
    
    //recursion with memoization
    int dpWithMemoization(int i, int j, string s, string t, vector<vector<int>> &memo){
        if(i>=s.size() or j>=t.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        
        if(s[i]==t[j]){
            return memo[i][j] = 1+dpWithMemoization(i+1, j+1, s, t, memo);
        }
        return memo[i][j] = dpWithMemoization(i, j+1, s, t, memo);
    }
};
