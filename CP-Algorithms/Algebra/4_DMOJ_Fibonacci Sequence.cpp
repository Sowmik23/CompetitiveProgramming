#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007  
typedef unsigned long long ull;

/*
 * verdict: worng(for test case when n==10^100000
 * 
 * but it works for n<=10^19
 */

/*
void multiply(ull F[2][2], ull M[2][2]){
	ull x = (F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod;
	ull y = (F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod;
	ull z = (F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod;
	ull w = (F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod;
	
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}


void power(ull F[2][2], ull n){
	if(n==0 or n==1) return;
	
	ull M[2][2] = {{1, 1}, {1, 0}};
	power(F, n/2);
	
	multiply(F, F);
	if(n%2!=0) multiply(F, M);
}


ull fibo(ull n){
	if(n==0) return 0;
	ull F[2][2] = {{1, 1}, {1, 0}};
	
	power(F, n-1);
	return F[0][0];
}
*/

map<ull, ull> fib;

ull f(ull n){
	if(fib.count(n)) return fib[n];
	ull k = n/2;
	
	if(n%2==0){  //n = 2*k
		return fib[n] = (f(k)*f(k) + f(k-1)*f(k-1))%mod;
	}
	else {   //n = 2*k+1
		return fib[n] = (f(k)*f(k+1) + f(k-1)*f(k))%mod;
	}
}



int main(){
		
	ull n;
	cin>>n;
	fib[0] = fib[1] = 1;
	
	if(n==0) cout<<"0"<<endl;
	else cout<<f(n-1)%mod<<endl;
	
	return 0;
}
