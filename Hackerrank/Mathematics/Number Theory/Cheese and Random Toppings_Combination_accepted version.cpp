#include <bits/stdc++.h>
using namespace std;

#define SIZE 100
#define ll long long 
#define inv(a, m) power(a, m-2, m)

vector<int>primes;

//nCr
//Combination ---> pascal triangle

void sieve() {
	char* s = new char [SIZE];
	int i, j;
	for(i = 2;i<SIZE;s[i++]=1);
	
	s[0] = s[1] = 0;
	
	for(i = 2;i*i<SIZE;i++){
		if(s[i]) {
			for(j = i*i;j<SIZE;j+=i){
				s[j] =0;
			}
		}
	}
	for(i=2;i<SIZE;i++){
		if(s[i]){
			primes.push_back(i);
		}
	}
	delete [] s;
}

ll power(ll a, ll b, ll mod) {
	ll res = 1;
	while(b){
		if(b&1) {
			res = (res*a)%mod;
		}
		b>>=1;
		a = (a*a)%mod;
	}
	return res;
}


ll fact(ll r, ll mod) {
	ll res = 1;
	for(ll i=2;i<=r;i++){
		res = (res*i)%mod;
	}
	return res;
}


ll comb(ll n, ll r, ll mod){
	ll res = inv(fact(r, mod), mod);
	ll nf = 1;
	for(ll i=0;i<r; i++){
		nf = (nf*(n-i))%mod;
	}
	res = (nf*res)%mod;
	return res;
}


ll crt(vector<ll> a, vector<ll> p, ll mod) {
	/**
	 * Calculate CRT 'x' such that
	 * x = a1 (mod p1), x= a2 (mod p2), ....
	 * a is obtained from lucas
	 */
	 ll x =0, ni;
	 ll len = p.size();
	 for(int i=0;i<len; i++) {
		 ni = mod/p[i];
		 x+= ni*inv(ni, p[i])*a[i];
	 }
	 return x;
 }


ll lucas(ll n, ll r, ll p) {
	ll res = 1;
	while(n>0){
		res = (res*comb(n%p, r%p, p))%p;
		n/=p;
		r/=p;
	}
	return res;
}


ll nCr(ll n, ll r, ll mod){
	vector<ll> p;
	vector<ll> a;
	
	for(ll i: primes){
		if(mod%i==0){
			p.push_back(i);
		}
	}
	ll len = p.size();
	for(ll i = 0; i < len; i++){
		a.push_back(lucas(n, r, p[i]));
	}
	
	return crt(a, p, mod)%mod;
}


int main(){
	
	int t;
	sieve();
	
	cin>>t;
	while(t--){
		ll n, r, m;
		cin>>n>>r>>m;
		
		cout<<nCr(n, r, m)<<endl;
	}
	
	return 0;
}
