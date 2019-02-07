#include <bits/stdc++.h>
using namespace std;

int prime[300000],nPrime;
int mark[1000002];

void sieve(int n)
{
	int limit = sqrt(n) + 2;
	mark[0]=mark[1]=1;  //as 1 and 0 are not prime.
	for(int i=4;i<=n;i+=2)
	{
		mark[i]=1;     //as almost all the evens are not prime.
	}
	prime[nPrime++]=2;
	for(int i=3;i<=n;i+=2)
	{
		if(!mark[i])
		{
			prime[nPrime++]=i;
			if(i<=limit)
			{
				for(int j=i*i;j<=n;j+=i*2)
				{
					mark[j]=1;   //j are not prime.
				}
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	sieve(n);
	for(int i=0;i<nPrime;i++)
	{
		cout<<prime[i]<<" ";
	}
	
	
	return 0;
}
