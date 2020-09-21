#include <bits/stdc++.h>
using namespace std;

/*
 * a^n
 *  Complexity: O(logn)
*/

#define ll long long 


//approach 01: recursively
ll binPow(ll a, ll n){
	
	if(n==0) return 1;
	ll res = binPow(a, n/2);
	
	if(n%2==0) return res*res;
	else return res*res*a;
}

//approach 02: without recursively
ll binPow1(ll a, ll n){
	ll res = 1;
	
	while(n>0){
		if(n&1) res = res*a;
		a = a*a;
		n>>=1;
	}
	return res;
}
	


int main(){
	
	ll a, n;
	cin>>a>>n;
	
	cout<<binPow1(a, n)<<endl;
	
	return 0;
}
