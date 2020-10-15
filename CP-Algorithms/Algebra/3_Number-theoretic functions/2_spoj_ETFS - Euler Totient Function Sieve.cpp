#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll mx = 1e7;

ll phi[9999999], primes[9999999], nPrime;
vector<bool> mark(mx, false);


void sieve(){
	
	for(ll i=4;i<=mx;i+=2) mark[i] = true;
	
	for(ll i=3;i*i<=mx;i+=2){
		if(mark[i]==false){
			for(ll j=i*i;j<=mx;j+=(2*i)){
				mark[j] = true;
			}
		}
	}
	for(ll i=2;i<=mx;i++) {
		if(mark[i]==false ) {
			primes[nPrime++] = i;
		}
	}
}


void phi_1_to_n(ll a, ll b){
	
	for(ll i=a;i<=b;i++) phi[i] = i;
	
	for(ll i=a;i<=b;i++){
		if(phi[i]==i){
			for(ll j=i;j<=mx;j+=i){
				phi[j]-=phi[j]/i;
			}
		}
	}
	
}


int main(){
	
	sieve();
	//cout<<"completed"<<endl;
	
	ll a, b;
	scanf("%lld%lld",&a, &b);
	
	
	phi_1_to_n(a, b);
	//cout<<"finished"<<endl;
	
	
	for(ll i=a;i<=b;i++){
		printf("%lld\n", phi[i]);
	}
	
	return 0;
}
