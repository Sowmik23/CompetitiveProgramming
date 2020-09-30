#include <bits/stdc++.h>
using namespace std;

/// Problem : Print the number of integers between 1 and n with 
/// exactly four divisors.

/// n(1<=n<=10^11)

typedef long long ll;


bool satisfy(ll n){
	int cnt=1;
	for(ll i=1;i<=n/2;i++){
		if(n%i==0) cnt++;
		if(cnt>4) return false;
	}
	//cout<<cnt<<endl;
	if(cnt==4) return true;
	return false;
}


int main(){
	
	ll n;
	scanf("%lld", &n);
	
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		//cout<<satisfy(i)<<" "<<i<<endl;
		if(satisfy(i)){
			cnt++;
		}
	}
	printf("%lld\n", cnt);
	
	
	return 0;
}
