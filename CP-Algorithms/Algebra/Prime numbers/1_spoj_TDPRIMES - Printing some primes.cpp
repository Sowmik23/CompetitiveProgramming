#include <bits/stdc++.h>
using namespace std;


/*Sieve of Eratosthenes
 * 
 * 
 * ##Works fine when n<=10^6
 */



typedef long long ll;


ll primes[8000000], nPrime=0, i, j;
vector<bool> mark(100000000, true);

void sieve(){
	ll n = 100000000;
	//ll limit = sqrt(n);
	
	mark[0] = mark[1] = false;  //mark false as 1 and 0 are not prime
	for(i=4;i<=n;i+=2) mark[i] = false; //as all evens are not prime

	//primes[nPrime++] = 2;
	//primes.push_back(2);
	//cout<<2<<" ";
	for(i=3;i*i<=n;i+=2){
		if(mark[i]) {
			//primes[nPrime++] = i;
			//cout<<i<<" ";
			//primes.push_back(i);
			for(j=i*i;j<=n;j+=(i*2)){
				mark[j] = false; //j are not primes as multiple of i
			}
		}
	}
	
	primes[nPrime++] = 2;
	for(i=3;i<=n;i+=2){
		if(mark[i]) primes[nPrime++] = i;
	}
}
	


int main(){
	
	//ll n;
	//cin>>n;
	
	sieve();
	
	 for(ll i=0;i<nPrime;i+=100){
		cout<<primes[i]<<endl;
	}
	//cout<<endl;
	//cout<<nPrime<<endl;
	
	return 0;
}
