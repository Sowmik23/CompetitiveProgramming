#include <bits/stdc++.h>

using namespace std;

#define ll long long

//Euler formula

//https://mathworld.wolfram.com/EulersCriterion.html


//This will provide the result of (base^exp)%mod in
// logarithmic time rather than quadratic time 
//without incurring overflow issues.
ll power(ll a, ll b, ll m){
	int ans = 1;
	a = a%m;
	while(b){
		if(b&1) ans = (ans*a)%m;
		a = (a*a)%m;
		b = b>>1;
	}
	return (ans%m);
}

int main(){
	
	ll t, a, m;
	cin>>t;
	while(t--){
		cin>>a>>m;
		
		if(a==0) {
			cout<<"YES"<<endl;
			continue;
		}
		ll x = power(a, (m-1)/2, m);
		
		if(x==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
