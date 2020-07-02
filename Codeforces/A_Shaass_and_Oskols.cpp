#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,x,y;
	scanf("%d",&n);
	int arr[n];
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		
		if((x-1>=1 and x-1<=n) or (x+1>=1 and x-1<=n))
		{
			arr[x-1] += (y-1);
			arr[x+1] += arr[x] - y;
			arr[x] = 0;
			//printf("%d %d %d %d\n",x,arr[x-1],arr[x],arr[x+1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",arr[i]);
	}
		
	
	return 0;
}
