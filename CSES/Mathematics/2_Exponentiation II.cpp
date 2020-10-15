#include <bits/stdc++.h>
using namespace std;



/// ***Special
/// https://www.geeksforgeeks.org/find-power-power-mod-prime/

typedef long long ll;

const ll mod = 1e9+7;


ll binExponentiation(ll a, ll b, ll mod){
	ll res = 1;
	a = a%mod;
	while(b>0) {
		if(b&1) res = res*a%mod;
		a = ((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	
	return res%mod;
}


int main(){
	ll n, a, b, c;
	
	scanf("%lld",&n);
	while(n--){
		scanf("%lld%lld%lld", &a, &b, &c);
		
		ll d = binExponentiation(b, c, mod-1);
		
		ll ans = binExponentiation(a, d, mod);
		
		printf("%lld\n", ans);
	}
	
	
	return 0;
}
