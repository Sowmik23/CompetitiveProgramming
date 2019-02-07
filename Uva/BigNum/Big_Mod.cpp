#include <bits/stdc++.h>
using namespace std;

long long bigmod(long long b,long long p,long long m)
{
	if(p==0) return 1;
	if(p%2==0)
	{
		long long c = bigmod(b,p/2,m);
		return (c*c)%m;
	}
	return (b*bigmod(b,p-1,m))%m;
}

int main()
{
	long long int b,p,m;
	while(scanf("%lld%lld%lld",&b,&p,&m)==3)
	{
		printf("%lld\n",bigmod(b,p,m));
	}
	
	return 0;
}
