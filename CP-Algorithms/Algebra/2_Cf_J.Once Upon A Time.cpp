#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

/*
 * Extended Euclidean algorithm
 * 
 */

ll x, y, d;

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
	
	ll n, m, a, k;
	while(1){
		cin>>n>>m>>a>>k;
		if(n==m and m==k and k==a and a==0) break;
		
		if(n==a) cout<<n<<endl;
		else {
			extendedEuclid(n+m, a+k);
			cout<<d*2<<endl;
		}
	}
	
	
	return 0;
}
