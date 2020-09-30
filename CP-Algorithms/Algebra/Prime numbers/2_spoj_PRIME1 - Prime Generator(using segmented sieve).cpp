#include <bits/stdc++.h>
using namespace std;

/*problem: Find primes in range l to r
 * 
 * ## r-l+1==1e7
 * 
 * ## r can be 1e12
 * 
 */

typedef long long ll;

/*
int const MAX = 100000;

bitset<MAX> prime, visited;
ll nPrime, primes[9000000];

vector<bool> mark(MAX, true);

///pre generating all the primes
void segmentedSieve() {
	///generate all primes up to sqrt(MAX)
	ll limit = (MAX);	
	
	mark[0] = mark[1] = false;
	for(ll i=4;i<=limit;i+=2) mark[i] = false;
	for(ll i=3;i*i<=limit;i+=2){
		if(!mark[i]){
			for(ll j=i*i;j<=limit;j+=(2*i)){
				mark[j] = false;
			}
		}
	}
	
	for(ll i=2;i<MAX;i++){
		if(mark[i]) primes[nPrime++] =i;
	}
}
*/

/*
///without pre-generating all the primes
vector<bool> segmentedSieveNoPreGen(ll l, ll r){
	vector<bool> isPrime(r-l+1, true);
	ll limit = sqrt(r);
	for(ll i=2;i<=limit;i++){
		for(ll j=max(i*i, (l+i-1)/(i*i));j<=r;j+=i){
			isPrime[j-l] =false;
		}
	}
	if(l==1) isPrime[0] = false;
	return isPrime;
}
*/


bool isPrime(ll n){
	if(n==0 or n==1) return false;
	else if(n!=2 and n%2==0) return false;
	else {
		for(ll i=3;i*i<=n;i+=2){
			if(n%i==0) return false;
		}
	}
	return true;
}


int main(){
	
	//segmentedSieve();
	
	ll m, n, t;
	scanf("%lld",&t);
	
	while(t--){
		scanf("%lld%lld",&m, &n);
	
		for(ll i=m;i<=n;i++){
			if(isPrime(i)) printf("%lld\n", i);
		}
		if(t) printf("\n");
		
		
		/*
		ll start;
		
		vector<bool>visited(n-m+1, true);
		
		for(ll i=0; i<nPrime; i++){
			start = 1ll*ceil(1.0*m/primes[i])*primes[i];
			if(start> n) break;
			for(ll j= start;j<=n;j+=primes[i]){
				if(j<MAX and !mark[j] || j>=MAX) visited[j-m] = false;
			}
		}
		
		
		for(ll i=m;i<=n;i++){
			if(i!=1 and visited[i-m]) printf("%lld ", i);
		}
		printf("\n");
		*/
	}
	
	return 0;
}
