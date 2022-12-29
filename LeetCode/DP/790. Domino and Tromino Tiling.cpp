class Solution {
public:
    int numTilings(int n) {
        // 1 1
        // 2 2
        // 3 5
        // 4 11
        // 5 24
        // 6 53
        // 7 117

        //so it follows a pattern: n = 2*(n-1)+(n-3)
        const int mod = 1e9 + 7;
        int a = 1;
        int b = 2;
        int c = 5;
        int d;
        if(n==1) return 1;
        else if(n==2) return 2;
        else if(n==3) return 5;
        else {
            for(int i=4;i<=n;i++){
                d = ((2*c)%mod+a)%mod;
                a = b;
                b = c;
                c = d%mod;
            }
        }

        return d%mod;
    }
};



class Solution {
public:
    int numTilings(int n) {

        if(n<=2) return n;
        if(n==3) return 5;

        int MOD = 1e9+7;
        long a = 1L;
        long b = 2L;
        long c = 5L;

        for(int i=4;i<=n;i++){
            long tmp = b;
            b = c;
            c = (2*c + a)%MOD;
            a = tmp;
        }

        return static_cast<int> (c);
    }
};
