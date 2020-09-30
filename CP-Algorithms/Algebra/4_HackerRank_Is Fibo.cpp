#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * problem: Fibonacci or not 
 * two approach:
 * 
 * #Approach01:  
 * We can pre-compute some Fibonacci Numbers.
 * Then for each query we do a binary search in the list to
 * find if that number exists. 
 * 
 * #Approach02:
 * N is a Fibonacci number if 5*N2 ± 4 is a perfect square
 * A smart way to check a number to be a 
 * perfect square is apply sqrt(N) % 1 == 0.
 */

///#Approach 01:

bool isPerfectSquare(ll a){
	double x = sqrt(a);
	
	if(x==(int)x) return true;
	else return false;
}


bool IsFibo(ll n){
	ll x = 5*n*n + 4;   //but when n==10^18 what will happen???
	ll y = 5*n*n - 4;
	
	if(isPerfectSquare(x) or isPerfectSquare(y)){
		return true;
	}
	else return false;
}

///#Alternative solution
map<ll, ll> isFibo;

void Fibonacci_Numbers(){
	ll a = 0;
	ll b = 1;
	ll c;
	while(1){
		c = a + b;
		if(c>10000000000LL) break;
		a = b;
		b = c;
		isFibo[c] = 1;
	}
}


int main(){
	int t;
	ll n;
	
	Fibonacci_Numbers();
	cin>>t;
	while(t--){
		cin>>n;
		
		if(isFibo[n]) cout<<"IsFibo"<<endl;
		else cout<<"IsNotFibo"<<endl;
	}
	
	return 0;
}
