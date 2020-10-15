#include <bits/stdc++.h>
using namespace std;

/// Concepts Needed:

/// Primes sieve() + Euler Totient() + Factorial() + Exponentiation()



typedef long long ll;
const int mx = 1e7;
const ll mod = 1e9+7;

int primes[mx+9], nPrime, mark[mx+9], cntPrime[mx+9];
int phi[mx+9];


void sieve(){
	for(int i=4;i<=mx;i+=2) mark[i] = 1;
	
	mark[2] = 0;
	for(int i=3;i*i<=mx;i+=2){
		if(mark[i]==0){
			for(int j=i*i;j<=mx;j+=(2*i)){
				mark[j] = 1;
			}
		}
	}
	
	
	for(int i=2;i<=mx;i++){
		if(mark[i]==0){
			primes[nPrime++] = i;
		}
		cntPrime[i] = nPrime;
	}
	//cout<<cntPrime[mx]<<" "<<mx<<endl;
}


void phi_1_to_n(){
	for(int i=2;i<=mx;i++) phi[i] = i;
	
	for(int i=2;i<=mx;i++){
		if(phi[i]==i){
			for(int j=i;j<=mx;j+=i){
				phi[j] -= phi[j]/i;
			}
		}
	}
	//cout<<phi[mx]<<" "<<mx<<endl;
}

void binaryExponentiation(ll a, ll b){
	ll res = 1;
	while(b>0){
		if(b&1) res = res*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	
	printf("%lld\n", res);
}



int main(){
	
	sieve();
	phi_1_to_n();
	
	int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		
		ll totnt = phi[n];	
		ll fn = cntPrime[n] - totnt;
		
		//cout<<cntPrime[n]<<" "<<phi[n]<<" "<<fn<<endl; 
		
		if(fn<0) fn = 0;
		
		ll factorial = 1;
		for(int i=2;i<=fn;i++){
			factorial*=i;
			factorial = factorial%mod;
		}
		//cout<<totnt<<" "<<factorial<<endl;
		
		if(n==1) cout<<"1"<<endl;
		else binaryExponentiation(totnt, factorial);
	}

	
	return 0;
}
