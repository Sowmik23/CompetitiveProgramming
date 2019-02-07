#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,m,k,x;
	int arr[600];
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=m;i++) arr[i]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&x);
			arr[x] = 1;
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		if(arr[i]==0) 
		{
			printf("NO\n");
			return 0;
		}	
	}
	printf("YES\n");
	
	return 0;
}
