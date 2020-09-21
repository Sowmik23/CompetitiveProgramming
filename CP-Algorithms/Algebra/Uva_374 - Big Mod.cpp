#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll bigMod(ll x, ll y, ll mod){
	if(y==0) return 1;
	ll res = bigMod(x, y/2, mod);
	
	if(y%2==0) return ((res%mod)*(res%mod))%mod;
	else return (res%mod*res%mod*x%mod)%mod;
}


int main(){
	
	ll b, p, m;
	while( cin>>b>>p>>m){
		ll res = 1;
		ll mod = m;
		while(p>0){
			if(p&1) res = ((res%mod)*(b%mod))%mod;
			b = (b%mod*b%mod)%mod;
			p>>=1;
		}
		cout<<res<<endl;
	} 
	
	return 0;
}

