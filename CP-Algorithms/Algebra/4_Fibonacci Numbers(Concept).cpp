#include <bits/stdc++.h>
using namespace std;

/* Fibonacci Numbers
 * 
 * Properties: 
 * 1. Cassini's identity: Fn-1*Fn+1 - F^2n = (-1)^n
 * 
 * 2. Addition Rule: Fn+k = Fk*Fn+1 + Fk-1*Fn
 * but when k==n: F2n = Fn(Fn+1 + Fn-1)
 * 
 * 3. GCD identity: GCD(Fm, Fn) = Fgcd(m, n)
 * 
 * #Find n-th fibonacci number:
 * 
 * Fn = ( ((1+sqrt(5))/2)^n - ((1-sqrt(5))/2)^n)/sqrt(5);
 * 
 * #Matrix for is more helpful
 * 
 */

typedef long long ll;

// This is not helpful when n>=10000 then use matrix multiplication rule

//Determine n-th fibonacci number: (Fast doubling method )
///Complexity: O(log n)
//it returns n-th and n+1 th fibo number
pair<ll, ll> fibo(ll n){
	if(n==0) return { 0, 1};
	//cout<<(n>>1)<<endl;
	auto p = fibo(n>>1);
	ll c = p.first*(2*p.second - p.first);
	ll d = p.first*p.first + p.second*p.second;
	
	if(n&1) return { d, c+d};
	else return {c, d};
}


int main(){
	
	ll n;
	
	cin>>n;
	
	pair<ll, ll> x = fibo(n);
	cout<<x.first<<" "<<x.second<<endl;
	
	return 0;
}
