// 1. Power of 2.cpp

int pow(int p, int q){
        long res = 1;
        while (q != 0) {
            if (q % 2 == 1) {   
                res = (res*(long long)p)%mod;
                res%=mod;
                q--;
            }
            else {
                q /= 2;   
                p = ((long long)p*p)%mod;  
                p%=mod;
            }
        }
        return (int)res%mod;
    }