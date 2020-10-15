#include <bits/stdc++.h>
using namespace std;

//verdict: wrong ans ;(

/// problem : https://codeforces.com/gym/100975/attachments/download/4285/20022003-petrozavodsk-summer-training-camp-saratov-su-contest-en.pdf
/// Problem F. Simple Calculation

typedef long long ll;

ll solve(ll n, ll mod){
	ll a = 2, b = n%mod, res = 1;
	while(b>0){
		if(b&1) res = res*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return res%mod;
}


int main(){
	
	ll n, k;
	
	cin>>n>>k;
	
	ll d = solve(n, k);
	
	ll ans = solve(d, k);
	
	cout<<(ans+1)%k;
	
	return 0;
}
