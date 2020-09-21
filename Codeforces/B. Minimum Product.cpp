#include <bits/stdc++.h>
using namespace std;

#define ll long long 


int main(){
	
	int t;
	cin>>t;
	
	ll a, b, x, y, n;
	
	while(t--){
		cin>>a>>b>>x>>y>>n;
		
		ll a1=a, b1=b, x1=x, y1=y, n1=n;
		
		ll diff1 = a-x;
		ll diff2 = b-y;
		
		ll d;
		if(diff1>diff2) d = diff2;
		else d = diff1;
		
				
		if(d>n) {
			if(d==diff1){
				a-=n;
				cout<<a*b<<endl;
			}
			else {
				b-=n;
				cout<<a*b<<endl;
			}
		}
		else {
			ll aa, bb;
			if(diff1>diff2){
				a= a - (n-diff1);
				b = b - (diff1);
			}
			else {
				aa= a - diff2;
				bb = b - (n-diff2);
			}
			ll r1 = a*b;
			ll r2 = aa*bb;
			
			cout<<min(r1, r2)<<endl;
		}
			
			
			
		
		/*while(true){
			if(n1<=0) break;
			if(a1>x1) {
				a1-=1;
				n1--;
			}
			else if(b1>y1){
				b1-=1;
				n1--;
			}
		}
		ll res = a1*b1;
		while(true){
			if(n<=0) break;
			if(b>y){
				b-=1;
				n--;
			}
			else if(a>x) {
				a-=1;
				n--;
			}
		}
		
		ll res2 = a*b;
		ll ans = min(res, res2);	
		cout<<ans<<endl;*/
	}
	
	return 0;
}






