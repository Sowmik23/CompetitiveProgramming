#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		int ans=n;
		int d,k;
		while(1)
		{
			if(n<3) break;
			d = n/3;
			ans+=d;
			k=n%3;
			n=d+k;
		}
		if(n==2) ans++;
		printf("%d\n",ans);
	}
	
	return 0;
}
