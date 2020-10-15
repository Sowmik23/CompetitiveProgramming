#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll primes[3000000], nPrime;
vector<bool> mark(500000000, true);

void sieve(){
	ll n = 6000000;
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
	for(ll i=3;i<=n;i++){
		if(mark[i]) primes[nPrime++] = i;
	}
}

vector<ll> v;

void calculate(){
	for(ll i=0;i<=400000;i++) {	//365560 don't ignore it
		for(ll j=i+1;j<=400000;j++){
			ll x = primes[i]*primes[j];
			if(x>60000000) break;
			v.push_back(x);
		}
	}
	sort(v.begin(), v.end());
	//ll len = v.size();
	//unique(v.begin(), v.end());
	//ll len = v.size();
	//cout<<len-999<<endl;
	//for(ll i=0;i<1000;i++){
		//cout<<v[i]<<" ";
	//}
}


int main(){
	
	sieve();
	//cout<<nPrime<<endl;
	//cout<<"finish"<<endl;
	calculate();
	int t;
	cin>>t;
	ll k;
	while(t--){
		
		cin>>k;
		
		cout<<v[k-1]<<endl;
	}
	
	return 0;
}
