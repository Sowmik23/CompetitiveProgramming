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
