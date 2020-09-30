#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * First use the Sieve of Eratosthenes technique 
 * to calcuate the number of prime factors for each 
 * number from 1 to 1M.
 * 
 * 
 * Then, build prefix-sum arrays  (a[i][j]=the number of integers
 * from 1 to j-th attribute−factorial)  for each i from 1 to 10.
 * 
 */

/*

///no need to do this
ll primes[1000000], nPrime;
vector<bool> mark(10000090, true);

void sieve(){
	ll n= 900000;
	mark[0] = mark[1] = false;
	for(ll i=4;i<=n;i+=2) mark[i] = false;
	
	for(ll i=3;i*i<=n;i+=2){
		if(mark[i]){
			for(ll j=i*i;j<=n;j+=(2*i)){
				mark[j] = false;
			}
		}
	}
	primes[nPrime++] = 2;
	for(ll i= 3;i<=n;i++){
		if(mark[i]) primes[nPrime++] = i;
	}
}
	
void printPrime(){
	for(ll i=0;i<nPrime;i++) cout<<primes[i]<<" ";
	cout<<endl;
}


bool fitFactor(ll x, ll n){
	int c=0;
	ll i=0;
	while(true) {
		//cout<<x<<" "<<primes[i]<<" "<<c<<endl;
		//long long d = primes[i]*primes[i];
		if(primes[i]>x) break;
		if(x%primes[i]==0) c++;
		if(c>n) return false;
		i++;
	}
	if(c==n) return true;
}
*/


///###First calculate the prime factors for each number

ll divisors[1000009];
ll arr[11][1000009];

void calculatePrimeFactors(){
	for(ll i=2;i<=1000000;i++){
		if(divisors[i]==0) {
			for(ll j= i;j<=1000000;j+=i){
				divisors[j]++;
			}
		}
	}


	///create prefix-sum array
	for(ll n=0;n<=10;n++){
		for(ll i=1;i<=1000000;i++){
			arr[n][i] = arr[n][i-1] + (bool) (divisors[i] == n);
		}
	}
} 



int main(){
	
	calculatePrimeFactors();
	ll t, a, b, n;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		
		int ans = arr[n][b] - arr[n][a-1];
		
		cout<<ans<<endl;
	}
	
	
	return 0;
}
