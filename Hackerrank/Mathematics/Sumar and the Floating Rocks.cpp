#include <bits/stdc++.h>

using namespace std;

//A single line containing the number of rocks.
//GCD || Divisors

#define ll long long 

ll gcd(ll a, ll b){
	ll x = a%b;
	if(x==0) return b;
	a = b;
	b = x;
	return gcd(a,b);
} 


int main(){
	
	ll t, x1,y1,x2,y2;
	
	cin>>t;
	while(t--){
		cin>>x1>>y1>>x2>>y2;
		
		//we need to go y1-y2 unit in y axis and x1-x2 unit in x axis;
		// that is slop m = (y1-y2)/(x1-x2);
		ll yy = abs(y1-y2);
		ll xx = abs(x1-x2);
		
		ll gd = __gcd(xx, yy);
		
		//ll zz = yy/gd;
		
		//ll ans = yy/zz - 1; // as excluding point P and Q so we reduce 1
		ll ans = gd - 1;
		
		cout<<ans<<endl;
		
	}
	
	
	return 0;
}
