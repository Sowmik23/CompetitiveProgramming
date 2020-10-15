#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

using u64 = uint64_t;
using u128 = __uint128_t;


/// It gets TLE so need to use Miller Rabin method
bool isPrime(ll n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}


u64 binpower(u64 base, u64 e, u64 mod){
	u64 res = 1;
	base%=mod;
	while(e){
		if(e&1) res = (u128)res*base%mod;
		base = (u128)base*base%mod;
		e>>=1;
	}
	return res;
}


bool check_composite(u64 n, u64 a, u64 d, int s){
	u64 x = binpower(a, d, n);
	
	if(x==1 or x==n-1) return false;
	for(int r=1;r<s;r++){
		x = (u128)x*x%n;
		if(x==n-1) return false;
	}
	return true;
}

/// Deterministic version
/// only checking all bases <= O((ln n)^2)
/// It's only necessary to test all bases a<=2 ln(n)^2

bool MillerRabin(u64 n) {  ///returns true if n is prime else false
	if(n<2) return false;
	
	int r = 0;
	u64 d = n - 1;
	while((d&1)==0) {
		d>>=1;
		r++;
	}

	for(int a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if(n==a) return true;
		if(check_composite(n, a, d, r)) return false;
	}
	return true;
	/*Another way...///Fermat primality test
	 int iter = 5;
	 if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
    */
}



int main(){
	
	ll n;
	
	scanf("%lld",&n);
	
	if(MillerRabin(n)) printf("YES\n");
	else printf("NO\n");
	
	
	return 0;
}

