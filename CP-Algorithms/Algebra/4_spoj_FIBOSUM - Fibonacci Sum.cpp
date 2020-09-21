#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long ll;

/*
 * 0 to n-th fibo sum is fibo(n+2) 
 * 
 * now think how to solve!
 */



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
	
	ll n, m;
	while(t--){
		ll sum = 0;
		cin>>n>>m;

		ll x = fibo(n+1);
		ll y = fibo(m+2);
		
		//cout<<y<<endl;
		sum = y%mod - x%mod + mod;  //one exception is here without adding mod I got wrong ans many times so be carefull.
		sum = sum%mod;
		
		cout<<sum<<endl;
	}
	
	return 0;
}
