#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll bigMod(ll a, ll n, ll mod){
	ll res = 1;
	while(n>0){
		if(n&1) res = (res * a)%mod;
		a = (a*a)%mod;
		n>>=1;
	}
	return res;
}

int main(){
		
	ll x, a, n, c;
	while(1){
		cin>>x>>a>>n>>c;
		if(x==a and n==c and a==c and a==0) break;
		
		ll total_gc = x;
		for(ll i=1;i<=n;i++){
			total_gc =(total_gc-1)*a;
			total_gc = total_gc%c;
		}
		
		if(total_gc<0) {
			total_gc+=c;
			total_gc = total_gc%c;
		}
		cout<<total_gc<<endl;
	}
	
	return 0;
}
