//Count Divisors of Factorial
//Legendre's formuls

#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long 

vector<ull> primes;

void seive(int n){
	
	//initialize all prime[i] as true
	vector<bool> prime(n+1, true);
	
	for(int i=2;i*i<=n;i++){
		if(prime[i]==true){
			for(int j=i*2;j<=n;j+=i){
				prime[j] = false;
			}
		}
	}
	//now store all the primes in primes vector
	for(int i=2;i<=n;i++){
		if(prime[i]==true) primes.push_back(i);
	}
}

ull factorialDivisors(ull n){
	ull res = 1;
	
	for(int i=0;i<primes.size();i++){
		ull p = primes[i];
		
		//find the highest power of all primes[i]
		//that divides n using legendre's formula
		ull exp = 0;
		while(p<=n){
			exp = exp + (n/p);
			p = p*primes[i];
		}
		
		res = res*(exp+1);
	}
	
	return res;
}


int main(){
	
	int n;
	cin>>n;
	
	seive(n);
	cout<<factorialDivisors(n)<<endl;
	
	return 0;
}
