#include <bits/stdc++.h>
using namespace std;


///help: https://forthright48.com/spoj-lcmsum-lcm-sum/

typedef long long ll;


ll res[1000009], phi[1000009];


void preCalculate(){
	/// Calculate phi from 1 to n using sieve
	
	for(int i=1;i<=1000000;i++){
		phi[i] = i;
	}
	
	for(int i=2;i<=1000000;i++){
		if(phi[i]==i){
			for(int j=i;j<=1000000;j+=i){
				phi[j] = phi[j]/i *(i -1);
			}
		}
	}
	
	/// Calculate partial result using sieve 
	/// For each divisor d of n, add phi(d)*d to result array
	for(ll i=1;i<=1000000;i++){
		for(ll j=i;j<=1000000;j+=i){
			res[j] += (i*phi[i]);
		}
	}
}



int main(){
	
	
	preCalculate();
	
	ll n;
	int t;
	scanf("%d",&t);
	
	while(t--){
		scanf("%lld",&n);
			
		/// we already have partial result in res[n];
		
		ll ans = res[n] + 1;
		ans*=n;
		ans = ans/2;
		
		printf("%lld\n", ans);
	}
	
	
	return 0;
}
