#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
ll primes[8000000], nPrime, i, j;
vector<bool> mark(10000000, true);


void seive(){
	ll n = 9999999;
	mark[0] = mark[1] = false;
	for(i = 4;i<=n;i+=2) mark[i] = false;
	
	for(i=3;i*i<=n;i+=2){
		if(mark[i]){
			for(j=i*i;j<=n;j+=(2*i)){
				mark[j] = false;
			}
		}
	}
	
	primes[nPrime++] = 2;
	for(i=3;i<=n;i++){
		if(mark[i]) primes[nPrime++] = i;
	}
}
*/

bool isPrime(ll x){
	for(ll i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

vector<ll> v;

void generate(){
	for(ll i=1;i*i<10000000;i++){
		for(ll j=1;j*j*j*j<10000000;j++){
			ll x = i*i + j*j*j*j;
			if(isPrime(x)) {
				//cout<<x<<" ";
				v.push_back(x);
			}
		}
	}
	
	sort(v.begin(), v.end());
	unique(v.begin(), v.end());  //remove duplicate primes
	//for(ll i=0;i<v.size();i++) cout<<v[i]<<" ";
}

int main(){
	
	int t;
	ll n;
	generate();
	int cnt ;
	cin>>t;
	while(t--){
		cnt=0;
		cin>>n;
		for(int i=0; ;i++){
			if(v[i]>n) break;
			cnt++;
		}
		cout<<cnt<<endl;
	}
			
	return 0;
}
