class Solution {
public:
    int concatenatedBinary(int n) {

        long mod = 1e9+7;
        int base=1;
        int res = 0;
        while(n>0){
            int x = n;
            while(x){
                int a = x%2;
                x /=2;
                res+=(base*a)%mod;
                base = (base*2)%mod;
                res%=mod;
            }
            n--;
        }
        return res%mod;
    }
};
