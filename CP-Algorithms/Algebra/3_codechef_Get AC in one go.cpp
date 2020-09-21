#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b, a%b);
}


int main(){
	ll t, a, b;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&a, &b);
		
		ll x = gcd(a, b);
		if(x==1) printf("%lld\n", a*b - a-b+1);
		else printf("-1\n");
	}
	
	
	
	return 0;
}
