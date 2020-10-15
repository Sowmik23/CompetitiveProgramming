#include <bits/stdc++.h>
using namespace std;


/* Simple Sieve of Eratosthenes
 * 
 * ##Works fine when n<=10^6
 * 
 * problems:
 * An array of size Θ(n) may not fit in memory
 * The simple Sieve is not cache friendly even for slightly bigger n. 
 * The algorithm traverses the array without locality of reference
 * 
 */

typedef long long ll;


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



int main(){
	
	sieve();
	
	printPrime();
	 /*for(ll i=0;i<nPrime;i++){
		cout<<primes[i]<<endl;
	}
	cout<<endl;
	cout<<nPrime<<endl;
	*/
	return 0;
}
