#include <bits/stdc++.h>
using namespace std;

/// Basic Implementation

typedef long long ll;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 49};
int arr[99999];


/// Find Number of Divisors of n
void D(int n){
	
	for(int i=0;i<15;i++){
		if(primes[i]*primes[i]>n) break;
		int cnt ;
		if(n%primes[i]==0){
			cnt = 0;
			while(n%primes[i]==0){
				cnt++;
				n/=primes[i];
			}
			arr[primes[i]] = cnt;
		}
	}
	if(n>1) arr[n]++;
	
	ll res = 1;
	for(int i=0;i<15;i++){
		//cout<<primes[i]<<" "<<arr[primes[i]]<<endl;
		
		if(arr[primes[i]]!=0){
			res *= (arr[primes[i]]+1);
		}
	}
	cout<<"Number of Divisors: "<<res<<endl;
} 

int binaryExponentiation(ll a, int b){
	ll ans = 1;
	while(b>0){
		if(b&1) ans = ans*a;
		a = a*a;
		b>>=1;
	}
	return ans;
}


///Find Sum of Divisors of n
void sigma(int n){
	
	ll res = 1;
	
	for(int i=0;i<15;i++){
		if(arr[primes[i]]>0) {
			res *= (binaryExponentiation(primes[i], arr[primes[i]]+1) - 1)/(primes[i]-1);
		}
	}
	
	cout<<"Sum of Divisors: "<<res<<endl;
}




int main(){
	
	int n;
	scanf("%d",&n);
	
	D(n);
	
	sigma(n);
	
	
	return 0;
}
