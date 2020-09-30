#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

/// Problem : https://www.spoj.com/problems/NGIRL/
/// Find n which has 3 divisors 


int primes[900000], nPrime;
vector<bool> mark(10000009, true);

ll lookup[100005];

const ll limit = 10000000000;


void sieve(){
	ll n = 100000;
	//cout<<n<<endl;
	mark[0] = mark[1] = false;
	for(int i=4;i<=n;i+=2) mark[i] = false;
	for(int i=3;i*i<=n;i+=2){
		if(mark[i]){
			for(ll j=i*i;j<=n;j+=(2*i)){
				mark[j] =false;
			}
		}
	}
	
	
	int cnt=0, last_prime;
	for(int i=2;i<=n;i++) {
		if(mark[i]){
			last_prime = i;
			cnt++;
		}
		lookup[i] = cnt;
		primes[i] = last_prime;
	}
}




int main(){
		
	sieve();
	//cout<<"finish"<<endl;
	
	int t;
	ll n, k;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n, &k);
			
		int n1 = sqrt(n);
		ll k1 = sqrt(k);
		
		int y = lookup[n1];
		int z = lookup[k1];
		
		int first=y;
		int second = first - z;
		
		if(k>n) second = 0;
		
		cout<<first<<" "<<second<<endl;
	}
	
	
	return 0;
}
	
