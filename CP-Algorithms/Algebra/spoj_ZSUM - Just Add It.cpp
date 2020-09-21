#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll bigMod(ll n, ll k){
	
	ll res = 1;
	while(k>0){
		if(k&1) res= (res%10000007*n%10000007)%10000007;
		n = (n*n)%10000007;
		k>>=1;
	}
	return res;
}


int main(){
		
	ll n, k;
	while(1){
		cin>>n>>k;
		if(n==0 and k==0) break;
		
		/*
		 * wrong process that I followed first 
		ll ans1 = 2*bigMod((n-1), k+n-1);
		ans1= ans1%10000007;
		ll ans2 = bigMod(n, k+n);
		ans2 = ans2%10000007;
		
		ll res = (ans1+ans2)%10000007;
		cout<<res<<endl;
		*/
		
		ll f = 2*bigMod((n-1), k)%10000007 + 2*bigMod((n-1), n-1)%10000007 + bigMod(n, k)%10000007 + bigMod(n, n)%10000007;
		f = f%10000007;
		cout<<f<<endl;
	}
	
	return 0;
}
