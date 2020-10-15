#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

ll phi(ll n){
	ll result = n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0){
				n/=i;
			}
			result -=result/i;
		}
	}
	if(n>1) result-=result/n;
	return result;
}


int main(){
	
	ll n;
	while(1) {
		cin>>n;
		if(n==0) break;
	
		if(n==1) cout<<0<<endl;
		else cout<<phi(n)<<endl;
	}
	
	return 0;
}
