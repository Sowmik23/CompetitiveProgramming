#include <bits/stdc++.h>
using namespace std;

#define ll long long 


int isPrime(ll n){
	if(n==1) return 0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	}
	return 1;
}


int main(){
	
	int t;
	cin>>t;
	ll number;
	while(t--){
		cin>>number;
	
		if(isPrime(number))  cout<<"Prime"<<endl;
		else cout<<"Not prime"<<endl;
	}
	
	return 0;
}
