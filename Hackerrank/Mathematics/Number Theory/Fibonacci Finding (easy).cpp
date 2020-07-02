// Fibonacci Series using Optimized Method 

#include <bits/stdc++.h> 
using namespace std; 

#define ll long long 

void multiply(ll F[2][2], ll M[2][2]); 
void power(ll a, ll b, ll F[2][2], ll n); 

// Function that returns nth Fibonacci number 
ll fibo(ll a, ll b, ll n) 
{ 
	ll F[2][2] = {{1, 1}, {b, a}}; 
	if (n == 1) 
		return b; 
	power(a, b, F, n - 1); 

	return F[0][0]; 
} 

// Optimized version of power() in method 4 
void power(ll a, ll b, ll F[2][2], ll n) 
{ 
	if(n == 0 || n == 1) return; 
	ll M[2][2] = {{1, 1}, {b, a}}; 
	
	power(a, b, F, n / 2); 
	multiply(F, F); 
	
	if (n % 2 != 0) 
		multiply(F, M); 
} 

void multiply(ll F[2][2], ll M[2][2]) 
{ 
	ll x = F[0][0] * M[0][0] + F[0][1] * M[1][0]; 
	ll y = F[0][0] * M[0][1] + F[0][1] * M[1][1]; 
	ll z = F[1][0] * M[0][0] + F[1][1] * M[1][0]; 
	ll w = F[1][0] * M[0][1] + F[1][1] * M[1][1]; 
	
	F[0][0] = x; 
	F[0][1] = y; 
	F[1][0] = z; 
	F[1][1] = w; 
} 

 
int main() 
{ 
	ll t, a, b, n;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
	
		cout << fibo(a, b, n)<<endl; 
	}
	
	return 0; 
} 
