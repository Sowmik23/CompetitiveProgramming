#include <bits/stdc++.h>

using namespace std;

//maximum number of unique prime factors for any number
// in the inclusive range 1 to n 

//int prime[50];
/*
void primes(){
	int k=0;
	for(int i=2;i<50;i++)
	{
		int cnt=0;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0) cnt++;
		}
		if(cnt==0) prime[k++] = i;
	}
	for(int i=0;i<k;i++){
		printf("%d ",prime[i]);
	}
}*/

int main()
{
	int q;
	unsigned long long n;
	int prime[50];
	int k=0;
	for(int i=2;i<50;i++)
	{
		int cnt=0;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0) cnt++;
		}
		if(cnt==0) prime[k++] = i;
	}
	
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%lld",&n);
		
		//primes();
		
		int sz = sizeof(prime)/sizeof(prime[0]);
		unsigned long long test = 1;
		int count = 0;
		if(n==1) count=0;
		else {
			for(int j=0;j<sz;j++){
				test*=prime[j];
				if(test<=n and test>0) count++;
				else break;
			}
		}
		printf("%d\n",count);
		
		
		/*int ans = 0;
		int cnt = 0;
		while(n%2==0){
			n /=2; // or n >>= 1;(equivalent)
			cnt++;
		}
		if(cnt) ans++;
		for(long long  i=3;i*i<=n;i+=2){
			cnt = 0;
			while(n%i==0){
				cnt++;
				n/=i;
			}
			if(cnt) ans++;
		}
		if(n>2) ans++;
		
		printf("%d\n",ans);*/
		
		
		
	}
	return 0;
}
