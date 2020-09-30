#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main(){
	int t;
	cin>>t;
	ll n;
	while(t--){
		cin>>n;
		
		ll sum=0;
		ll a = 0, b= 1, c;
		while(true){
			c = a+b;
			if(c>n) break;
			if(c%2==0) sum+=c;
			a = b;
			b = c;
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
