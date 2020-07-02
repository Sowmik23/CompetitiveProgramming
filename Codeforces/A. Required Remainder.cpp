#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	
	ll t, x, y, n, k;
	cin>>t;
	while(t--){
		cin>>x>>y>>n;
		
		ll ans;
		ll res = n%x - y;
		//cout<<res<<endl;
		
		if(res<0){
			ans = (res+x);
		}
		else ans = res;
		
		ll d = n-ans;
		//cout<<d<<" "<<ans<<endl;
		//if(d > ans) cout<<d<<endl;
		cout<<d<<endl;
	}
	
	
	return 0;
}
