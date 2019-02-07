#include <bits/stdc++.h>
using namespace std;

#define mx 1e9

int arr[51],visited[51][51];

int dp(int i,int j)
{
	if(i+1==j) return 0;
	if(visited[i][j]!=-1) return visited[i][j];	
	
	int res = mx;
	
	for(int k=i+1;k<j;k++)
	{
		int x = dp(i,k)+dp(k,j)+(arr[j]-arr[i]);
		res = min(res,x);
	}
	return visited[i][j] = res;
}

int main()
{
	int l,n;
	while(scanf("%d",&l))
	{
		if(l==0) break;
		scanf("%d",&n);
		
		arr[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
		}
		arr[n+1] = l;

		memset(visited,-1,sizeof(visited));
		printf("The minimum cutting is %d.\n",dp(0,n+1));
	}
	
	return 0;
}
