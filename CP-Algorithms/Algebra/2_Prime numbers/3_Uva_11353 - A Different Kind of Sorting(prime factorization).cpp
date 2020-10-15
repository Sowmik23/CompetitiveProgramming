#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//Prime factorization
//based on number of prime divisor
//sort the array


const ll MAX = 2000001;

ll pprimes[2000005], nPrime;
ll spf[2000005];


///O(n log log n)
void sieve(){
	spf[1] = 1;
	
	///marking smallest prime factor for each number to be itself first
	for(ll i=2;i<=MAX;i++){
		spf[i] = i;
	}
	
	
	///marking spf for every even number as 2
	for(ll i=4;i<=MAX;i+=2) spf[i] = 2;
	
	for(ll i=3;i*i<=MAX;i++){
		if(spf[i] ==i){
			for(ll j=i*i;j<=MAX;j+=i){
				if(spf[j]==j) spf[j] = i;
			}
		}
	}
}


struct Calculate {
	ll a, b;
}arr[2000005];

bool cmp(Calculate first, Calculate second){
	if(first.b==second.b) return first.a < second.a;
	else return first.b<second.b;
}


void factorize() {
	ll cnt;
	for(ll i=1;i<=MAX;i++){
		ll x = i;
		cnt=0;
		while(x!=1){
			cnt++;
			x = x/spf[x];
		}
		arr[i].a = i;
		arr[i].b = cnt;
	}
	//for(int i=0;i<200;i++) cout<<arr[i].a<<" "<<arr[i].b<<endl;
	sort(arr, arr+MAX, cmp);
	//for(int i=0;i<200;i++) cout<<arr[i].a<<" "<<arr[i].b<<endl;
}


int main(){
	sieve();
	//cout<<"finished"<<endl;
	factorize();
	//cout<<"finished2"<<endl;
	ll n;
	for(int cs=1; ; cs++) {
		scanf("%lld",&n);
		if(n==0) return 0;
	
		printf("Case %lld: %lld\n",cs, arr[n].a);
	}
	
	
	return 0;
}
