#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*Simple! first find the  n+1-th fibo number
 * 
 * then mod it with 2^m 
 * 
 */

int m;
ll mod;

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



ll fibo(ll n){
	ll F[2][2] = {{1, 1}, {1, 0}};
	if(n==0) return 0;
	
	power(F, n-1);
	return F[0][0];
}


int main(){
	
	int t;
	ll n;
	cin>>t;
	while(t--){
		cin>>n>>m;
		mod = pow(2, m);
		ll x = fibo(n+1)%mod;
		//ll z = fibo(n-1)%mod;	
		//cout<<x<<endl;
	
		int res = (x)%mod;
		cout<<res<<endl;
	}
	
	return 0;
}
