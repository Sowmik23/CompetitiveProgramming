
#include <bits/stdc++.h> 
using namespace std;


struct output{
	long long a,b;
} res[500000];

long long divisors[10000];
// function to print the divisors 
/*
void printDivisors(int n) 
{ 
	int k=0;
	for (int i=2;i*i<=n;i++) {
		if (n%i==0) {
			cout<<i<<endl;
			divisors[k++] = i;
		} 
	}
	for(int i=0;i<k-1;i++){
		for(int j=i+1;j<k;j++){
			int sum = divisors[i] + divisors[j];
			if ( __gcd(n, sum) == 1) {
				res[
	}
} 
*/


int main() 
{ 
	//printDivisors(100); 
	
	long long t,n;
	scanf("%lld",&t);
	long long arr[t];
	for(int l=0;l<t;l++){
		scanf("%lld",&arr[l]);
		n = arr[l];
		
		int k=0;
		for (int i=2;i<=n;i++) {
			if (n%i==0) {
				divisors[k++] = i;
			} 
		}
		int flag = 0;
		for(int i=0;i<k-1;i++){
			for(int j=i+1;j<k;j++){
				long long sum = divisors[i] + divisors[j];
				if ( __gcd(n, sum) == 1) {
					flag = 1;
					res[l].a = divisors[i];
					res[l].b = divisors[j];
					break;
				}
			}
			if(flag==1) break;
		}
		if(flag==0){
			res[l].a = -1;
			res[l].b = -1;
		}	
	}
	
	for(int i=0;i<t;i++){
		if(i) printf(" %lld",res[i].a);
		else printf("%lld",res[i].a);
	}
	printf("\n");
	for(int i=0;i<t;i++){
		if(i) printf(" %lld",res[i].b);
		else printf("%lld",res[i].b);
	}
	printf("\n");
	
	return 0; 
} 
