#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;


void binExponentiation(int a, int b){
	ll res = 1;
	a = a%mod;
	while(b>0) {
		if(b&1) res = res*a%mod;
		a = ((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	res = res%mod;
	printf("%lld\n", res);
}


int main(){
	int n, a, b;
	
	scanf("%d",&n);
	while(n--){
		scanf("%d%d", &a, &b);
		
		binExponentiation(a, b);
	}
	
	
	return 0;
}
