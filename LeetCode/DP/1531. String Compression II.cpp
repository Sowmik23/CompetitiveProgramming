// 1531. String Compression II

int dp[101][27][101][101]; //there is a difference in declaring dp here and inside private 

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        
        //dynamic programming
        int n = s.size();
        //get prev char as input to reduce prev and treat 26 as -1

        //recursive
        // return recursive(s, 0, 26, k, 0);

        //recursion with memoization
        memset(dp, -1, sizeof(dp));
        return recursionWithMemo(s, 0, 26, k, 0);
    }
private:
    int recursive(string &s, int idx, int prev, int k, int cnt){
        if(k<0) return INT_MAX;
        if(idx>=s.size()) return 0;

        int acc = INT_MAX;
        int del = INT_MAX;

        del = recursive(s, idx+1, prev, k-1, cnt);
        if(prev+'a'==s[idx]){
            if(cnt==1 or cnt==9 or cnt==99){
                acc = 1 + recursive(s, idx+1, prev, k, cnt+1);
            }
            else acc = recursive(s, idx+1, prev, k, cnt+1);
        }
        else {
            acc = 1 + recursive(s, idx+1, s[idx]-'a', k, 1);
        }

        return min(del, acc);
    }
    int recursionWithMemo(string &s, int idx, int prev, int k, int cnt){
        if(k<0) return 1e9;
        if(idx>=s.size()) return 0;

        if(dp[idx][prev][k][cnt]!=-1) return dp[idx][prev][k][cnt];

        int acc = INT_MAX;
        int del = recursionWithMemo(s, idx+1, prev, k-1, cnt);
        if(prev+'a'==s[idx]){
            if(cnt==1 or cnt==9 or cnt==99){
                acc = 1 + recursionWithMemo(s, idx+1, prev, k, cnt+1);
            }
            else acc = recursionWithMemo(s, idx+1, prev, k, cnt+1);
        }
        else {
            acc = 1 + recursionWithMemo(s, idx+1, s[idx]-'a', k, 1);
        }

        return dp[idx][prev][k][cnt] = min(del, acc);
    }
};