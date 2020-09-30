#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	
	ll n;
	int t;
	cin>>t;
	while(t--){
		//ll cnt =1;
		
		cin>>n;
		
		ll k = (sqrt(n));
		//cout<<sqrt(n)<<" "<<k<<" ";
		
		ll ans = k + (n/k) - 2;
		
		if(n%k!=0) ans++;
		
		cout<<ans<<endl;
	
				
	}
		
		/*
		ll x = 1;
		ll sum=0;
		int flag = 1;
		sum+=x;
		if(sum>=n) {
			cout<<0<<endl;
			continue;
		}
		while(1) {
			cnt++;
			if(flag) {
				x = x+1;
				sum+=x;
				flag = 0;
			}
			else {
				ll nw = x+x;
				flag=1;
				sum+=nw;
			}
			if(sum>=n) {
				cout<<cnt<<endl;
				break;
			} 
		}
		*/
	
	
	return 0;
}
