#include <bits/stdc++.h>
using namespace std;

/* problem: ax + by = gcd(a, b) = d
 * 
 * Given a and b 
 * 
 * find x, y and gcd(a,b)
 * 
 */

typedef long long ll;

ll x, y , d;

void extendedEuclid(ll a, ll b){
	if(b==0){
		x = 1;
		y = 0;
		d = a;
		return ;
	}
	extendedEuclid(b, a%b);
	ll x1, y1;
	x1 = y;
	y1 = x - y*(a/b);
	x = x1;
	y = y1;
	return ;
}
	

int main(){
	ll a, b;
	
	while(cin>>a>>b){
		
		extendedEuclid(a, b);
		
		cout<<x<<" "<<y<<" "<<d<<endl;
	}
	
	
	return 0;
}
