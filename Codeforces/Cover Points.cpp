#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,mx=-1;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		mx = max(mx,a+b);
	}
	printf("%d\n",mx);
	
	return 0;
}
