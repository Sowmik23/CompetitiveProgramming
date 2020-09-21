#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	
	int t, a;
	ll b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		
		ll res = 1;
		while(b>0){
			if(b&1) res = (res*a)%10;
			a = (a*a)%10;
			b>>=1;
		}
		printf("%01lld\n",res);
	}
	
	return 0;
}
