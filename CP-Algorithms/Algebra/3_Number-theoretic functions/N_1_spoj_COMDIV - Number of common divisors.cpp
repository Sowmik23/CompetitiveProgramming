#include <bits/stdc++.h>
using namespace std;


/// The number of common divisors of two numbers is simply
/// the number of divisors of their gcd()

const int mx = 1e6+1;

//int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int ans[mx];

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}

void D(int n){
	/*
	int arr[99999]={0};
	int cnt;
	for(int i=0;i<15;i++){
		if(primes[i]*primes[i]>n) break;
		if(n%primes[i]==0){
			cnt = 0;
			while(n%primes[i]==0){
				cnt++;
				n/=primes[i];
			}
			arr[primes[i]]= cnt;
		}
	}
	if(n>1) arr[n] = 1;
	
	int ans=1;
	for(int i=0;i<15;i++){
		if(arr[primes[i]]>0){
			ans *= (arr[primes[i]] + 1);
		}
	}
	
	printf("%d\n", ans);
	*/
	
	/// It takes less time then above . we precalculate here like dp.
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			ans[n]++;
			if(n/i !=i) ans[n]++;
		}
	}
}



int main(){
	
	int t, a, b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a, &b);
		
		int d = gcd(a, b);
		
		if(ans[d]==0) D(d);

		printf("%d\n", ans[d]);
	}

	
	return 0;
}
