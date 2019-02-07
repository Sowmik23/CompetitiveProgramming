#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int n,m;
int arr[15][105],visited[15][105],ans[15][105];

int dp(int i,int j)
{
	if(j>=m) return 0;

	if(visited[i][j]!=INF) return visited[i][j];
	
	int brr[3] ={ i-1,i,i+1};
	if(i==0) brr[0] = n-1;
	if(i==n-1) brr[2] = 0;
	
	for(int k=0;k<3;k++) 
	{
		int res = dp(brr[k], j+1) + arr[i][j];
		if(visited[i][j] > res || (visited[i][j]==res and ans[i][j]>brr[k]))
		{
			visited[i][j] = res;
			ans[i][j] = brr[k];
		}
	}
			 
	return visited[i][j];
}

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&arr[i][j]);
				visited[i][j] = INF;
			}
		}
		
		int d = INF,x=0;
		for(int i=0;i<n;i++)
		{
			dp(i,0);
			if(visited[i][0] <d)
			{
				d = visited[i][0];
				x = i;
			}
		}
		for(int j=0;j<m;j++)
		{
			if(j) cout<<" ";
			printf("%d",x+1);
			x = ans[x][j];
		}
	
		printf("\n%d\n",d);
	}
	
	return 0;
}
