#include <bits/stdc++.h>
using namespace std;

/*
 * Accually we need to apply lames theorm:
 * 
 * to find the gcd(a,b):
 * 
 * For a given positive integer n, 
 * let a > b be the least integers such that 
 * Euclid's algorithm applied to a and b requires 
 * exactly n division steps. Then a = un+2 and b = un+1 
 * (where un is the nth Fibonacci number).
 */


///Time & Space complexity: O(log n)

#define mod 1000000007
typedef long long ll;


void multiply(ll F[2][2], ll M[2][2]){
	ll x = (F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod;
	ll y = (F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod;
	ll z = (F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod;
	ll w = (F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod;

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(ll F[2][2], ll n){
	if(n==0 or n==1) return ;
	ll M[2][2] = {{1, 1}, {1, 0}};
	
	power(F, n/2);
	multiply(F, F);
	
	if(n%2!=0) multiply(F, M);
}


ll fibo(ll n) {
	ll F[2][2] = {{1, 1}, {1, 0}};
	if(n==0) return 0;
	
	power(F, n-1);
	
	return F[0][0];
}


int main(){
		
	int t;
	cin>>t;
	ll n;
	while(t--){
		cin>>n;
		
		if(n==0) cout<<"0"<<endl;
		else if(n==1) cout<<"2"<<endl;
		else cout<<fibo(n+3)%mod<<endl;
	}
	
	
	return 0;
}
