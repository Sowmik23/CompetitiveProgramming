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
	
	ll c, x, y, n, lastNum;
	cin>>c;
	while(c--){
		cin>>x>>y>>n;
		
		//Accepted
		//cout<<bigMod(x, y, n)<<endl;
		
		ll res = 1;
		ll mod = n;
		while(y>0){
			if(y&1) res = ((res%mod)*(x%mod))%mod;
			x = (x%mod*x%mod)%mod;
			y>>=1;
		}
		cout<<res<<endl;
	} 
	cin>>lastNum;
	
	
	return 0;
}
