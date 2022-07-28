class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        
        if(s3.size()!=(s1.size()+s2.size())) return false;
        
        //recursion
        //return recursion(s1, s2, s3, s1.size()-1, s2.size()-1, s3.size()-1);
    
        //recursion with memoization
        vector<vector<int>> memo(s1.size()+1, vector<int> (s2.size()+1, -1));
        return recursionWithMemo(s1, s2, s3, s1.size()-1, s2.size()-1, s3.size()-1, memo);
    }
private:
    bool recursion(string s1, string s2, string s3, int i, int j, int k){
        if(i<0 and j<0 and k<0) return true;
        
        if((i>=0 and s1[i]==s3[k]) and (j>=0 and s2[j]==s3[k])){
            return recursion(s1, s2, s3, i-1, j, k-1) or recursion(s1, s2, s3, i, j-1, k-1);
        }
        else if(i>=0 and s1[i]==s3[k]){
            return recursion(s1, s2, s3, i-1, j, k-1);
        }  
        else if(j>=0 and s2[j]==s3[k]){
            return recursion(s1, s2, s3, i, j-1, k-1);
        }
           
        else return false;
    }
    
    bool recursionWithMemo(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &memo){
        if(i<0 and j<0 and k<0) return true;
        if(i>=0 and j>=0 and memo[i][j]!=-1) return memo[i][j];
        
        if((i>=0 and s1[i]==s3[k]) and (j>=0 and s2[j]==s3[k])){
            return memo[i][j] = recursionWithMemo(s1, s2, s3, i-1, j, k-1, memo) or recursionWithMemo(s1, s2, s3, i, j-1, k-1, memo);
        }
        else if(i>=0 and s1[i]==s3[k]){
            return recursionWithMemo(s1, s2, s3, i-1, j, k-1, memo);
        }  
        else if(j>=0 and s2[j]==s3[k]){
            return recursionWithMemo(s1, s2, s3, i, j-1, k-1, memo);
        }
           
        else return false;
    }
};
