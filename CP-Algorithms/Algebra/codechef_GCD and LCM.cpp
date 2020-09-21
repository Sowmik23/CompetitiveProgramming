#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b, a%b);
}



int main(){
	
	int t;
	cin>>t;
	
	ll a, b;
	while(t--){
		cin>>a>>b;
		
		ll x = gcd(a, b);
		
		ll lcm = (a*b)/x;
		
		cout<<x<<" "<<lcm<<endl;
	}
	
	
	return 0;
}
