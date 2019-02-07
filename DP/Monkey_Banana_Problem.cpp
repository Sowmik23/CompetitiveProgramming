#include <bits/stdc++.h>
using namespace std;

int n,arr[205][105],visited[205][205];

long long dp(int row ,int col)
{
	if(row<0 || col<0) return 0;
	if(col>row) return 0;

	if(visited[row][col]!=-1) return visited[row][col];
	if(visited[row][col]==-1)
	{
		if(row<n)
		{
			visited[row][col] = max( dp(row-1,col-1),dp(row-1,col) ) + arr[row][col];
		}
		else 
		{
			visited[row][col] = max(dp(row-1,col),dp(row-1,col+1)) + arr[row][col];
		}
	}
	return visited[row][col];
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		scanf("%d",&n);
		memset(visited,-1,sizeof(visited));
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				//printf("%d %d ",i,j);
				scanf("%d",&arr[i][j]);
			}
		}
		int l=n-1;
		for(int i=n;i<(2*n-1);i++)
		{
			for(int j=0;j<l;j++)
			{
				//printf("%d %d ",i,j);
				scanf("%d",&arr[i][j]);
			}
			l--;
		}
		long long ans = dp(2*n-2,0);
		
		printf("Case %d: %lld\n",k,ans);
	}
	
	return 0;
}
