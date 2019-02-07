#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long  n,s;
	scanf("%lld%lld",&n,&s);
	long long  arr[n+10];
	
	long long  cnt=0;
	
	for(long long  i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		if(arr[i]>=s) cnt++;
	}
	if(cnt==0) printf("-1\n");
	else printf("%lld\n",cnt);
	
	return 0;
}
