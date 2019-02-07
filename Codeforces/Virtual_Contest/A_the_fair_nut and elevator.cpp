#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long  n,s;
	scanf("%lld",&n);
	long long  sum=0;
	
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&s);
		sum+=s*i;
	}
	printf("%lld\n",sum*4);
	
	return 0;
}
