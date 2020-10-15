#include <bits/stdc++.h>
using namespace std;


/// Problem: https://www.spoj.com/problems/FACT1/
/// Integer Factorization (20 digits) FACT1 Spoj

/// Miller Rabin + Rho  algorithm


#define ll __int128_t
ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int nPrime = sizeof(primes)/sizeof(ll);

map<ll, int> fact;




/// The inline functions are a C++ enhancement feature
/// It increase the execution time of a program
inline ll add(ll a, ll b, ll mod) {
	return (__int128_t) a+b%mod;
}

inline ll mult(ll a, ll b, ll mod){
	return (__int128_t)a*b%mod;
}

inline ll f(ll a, ll mod, ll c){
	return add(mult(a, a, mod), c, mod);
}

/// Returns (a^b)%mod
ll bigmod(ll a, ll b, ll mod){
	a%=mod;
	ll res = 1%mod;
	while(b){
		if(b&1) res = mult(res, a, mod);
		a = mult(a, a, mod);
		b>>=1;
	}
	return res;
}


/// Returns true if n is a prime else false
bool millerRabin(ll n){
	if(n<2 or (n!=2 and n%2==0)) return false;
	int s = 0;
	ll d = n-1;
	while((d&1)==0){
		s++;
		d>>=1;
	}
	
	for(int i=0;i<nPrime and primes[i]<n-1; i++) {
		ll x = bigmod(primes[i], d, n);
		if(x==1 or x==n-1) continue;
		int cmp = 1;
		for(int j=1;j<s;j++){
			x = mult(x, x, n);
			if(x==1) return false;
			else if(x==n-1) {
				cmp = 0;
				break;
			}
		}
		if(cmp) return false;
	}
	return true;
}
		


ll rho(ll x, ll n){
	ll y = x;
	ll d = 1;
	while(d==1) {
		x = f(x, n, 1);
		y = f(y, n, 1);
		y = f(y, n, 1);
		d = __gcd(x>y ? x-y:y-x, n);
	}
	return d;
}


/// Implementation of brent algorithm
/// Simillar as pollard rho and floyed's integer factorization algorithm
/*ll brent(ll n, ll x0=2, ll c=1) {
    ll x = x0;
    ll g = 1;
    ll q = 1;
    ll xs, y;

    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = mult(q, (y - x), n);
            }
            g = __gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = __gcd((xs - y), n);
        } while (g == 1);
    }
    return g;
}*/



void factorize(ll n){
	if(n==1) return;
	if(millerRabin(n)) {
		fact[n]++;
		return ;
	}
	
	ll d = n;
	for(int i=0;i<nPrime and primes[i]<n-1 and d==n;i++){
		d = rho(primes[i], n);
	}
	if(d==n){
		while(n%2==0) {
			fact[2]++;
			n = n/2;
		}
		for(int i=3;i*i<=n;i+=2) {
			while(n%i==0) {
				fact[i]++;
				n/=i;
			}
		}
		if(n>1) fact[n]++;
	}
	else {
		factorize(d);
		factorize(n/d);
	}
}



/// take 20 digit(max) length input
ll take_input(){
	string str;
	cin>>str;
	ll n =0;
	int len = str.size();
	for(int i=0;i<len;i++) {
		n = n*10 + str[i]-'0';
	}
	return n;
}


void output(ll n){
	string str;
	while(n){
		str.push_back(n%10+'0');
		n/=10;
	}
	reverse(str.begin(), str.end());
	cout<<str;
}


int main() {
	
	ll n;
	
	while((n=take_input()) and n){
		fact.clear();
		factorize(n);
		for(auto x: fact) {
			output(x.first);
			printf("^%d ",x.second);
		}
		printf("\n");
	}
	
	return 0;
}

