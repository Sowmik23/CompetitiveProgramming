//HARD QUESTION: TODO


class Solution {
    const static int N = 127;
    int dp[N][N];
    int n;
    string str;

    inline int helper(int cnt){ return cnt==1 ? 0 : cnt<10 ? 1: cnt<100 ? 2 : 3; }

public:
    int getLengthOfOptimalCompression(string s, int k) {

        n = s.size();
        str = s;
        memset(dp, -1, sizeof(dp));

        return solve(k, 0);
    }

    int solve(int k, int left){
        if(k<0) return N; //invalid, return inf
        if(left>=n or n-left<=k) return 0; //empty string

        int &res = dp[left][k];
        if(res!=-1) return res;
        res = N;

        int cnt[26] = {0};
        int most = 0;

        for(int j=left;j<n;j++){
            cnt[str[j]-'a']++;
            most = max(most, cnt[str[j]-'a']);
            res = min(res, 1+ helper(most) + solve(k-(j-left+1-most), j+1));
        }
        return res;
    }
};
