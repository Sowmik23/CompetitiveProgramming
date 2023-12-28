// 2466. Count Ways To Build Good Strings
class Solution {
public:
    const int mod = 1e9+7;
    vector<int> memo;
    int countGoodStrings(int low, int high, int zero, int one) {
        
        int res = 0;
        memo = vector<int> (high+1, -1);
        memo[0] = 1;

        for(int len=low;len<=high;len++){
            res+=recursive(zero, one, len);
            res%=mod;
        }
        return res;
    }
private:
    int recursive(int zero, int one, int len){

        if(len==0) return 1;
        if(len<0) return 0;
        if(memo[len]!=-1) return memo[len]%mod;

        long cnt = 0;
        cnt = recursive(zero, one, len - zero) + recursive(zero, one, len - one);
        memo[len] = cnt%mod;
        return memo[len];
    }
};