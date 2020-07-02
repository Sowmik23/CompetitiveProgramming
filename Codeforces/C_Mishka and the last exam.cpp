#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	scanf("%lld",&n);
	long long int arr[n],brr[n+10];
	
	for(int i=1;i<=n/2;i++)
	{
		scanf("%lld",&arr[i]);
	}
	
	for(int i=1;i<=n/2;i++)
	{
		long long int x = arr[i];
		
		if(i==1)
		{
			brr[i]=0;
		}
		else 
		{
			brr[i]=max(brr[i-1],x-brr[n-i+2]);
		}	
		brr[n-i+1] = x-brr[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		if(i!=1) printf(" ");
		printf("%lld",brr[i]);
	}	
	
	return 0;
}
