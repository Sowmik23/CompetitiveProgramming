#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


//ll primes[5000000], nPrime;
vector<bool> mark(1000009, true);

void sieve(){
	
	mark[0] = mark[1] = false;
	
	for(ll i=4;i<=1000000;i+=2) mark[i] = false;
	
	for(ll i=3;i*i<=1000000;i+=2){
		if(mark[i]){
			for(ll j=i*i;j<=1000000;j+=(2*i)){
				mark[j] = false;
			}
		}
	}
	//primes[nPrime++] = 2;
	//for(ll i=3;i<=n;i++){
		//if(mark[i]) primes[nPrime++] = i;
	//}
}

ll exponent(ll x, ll y){
	ll res = 1;
	while(y>0) {
		if(y&1) res = res*x;
		x = x*x;
		y>>=1;
	 }
	 return res;
}

bool afraid(ll x){
	ll digit = 0;
	ll tmp = x;
		
	while(x>0){
		if(x%10==0) return false;
		digit++;
		x/=10;
	}
	
	//we need to do this segment as 
	//truncations (632647, 32647, 2647, 647, 47, and 7) are primes.
	ll div = exponent(10LL, digit-1);
	x = tmp;
	while(x>0){
		x = x%div;
		div/=10;
		if(x!=0 and mark[x]==false) return false;
	}
	return true;
}

	
ll cnt[1000009];

void preCalculation(){
	cnt[0] = cnt[1] = 0;
	for(ll i=2;i<=1000000;i++) {
		cnt[i]= cnt[i-1];
		
		if(mark[i]) {
			if(afraid(i)) cnt[i]++;
		}
	}
}



int main(){
	
	ll t, n;
	sieve();
	//cout<<"finish"<<endl;
	preCalculation();
	//cout<<"finish"<<endl;
	cin>>t;
	while(t--){
		cin>>n;
	
		cout<<cnt[n]<<endl;
	}
	
	return 0;
}
