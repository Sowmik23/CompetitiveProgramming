#include <bits/stdc++.h>
using namespace std;

int n,m,arr[100],visited[100][100];

int dp(int i,int d)
{
	if(i==m) return 1;
	if(visited[i][d]!=-1) return visited[i][d];
	visited[i][d]=0;
	for(int j=0;j<n;j++)
	{
		if(i==0) visited[i][d]+=dp(i+1,arr[j]);
		else 
		{
			if(abs(d-arr[j])<=2)
			{
				visited[i][d] +=dp(i+1,arr[j]);
			}
		}
	}
	return visited[i][d];
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		memset(visited,-1,sizeof(visited));
		
		int ans = dp(0,n);
		
		printf("Case %d: %d\n",k,ans);
	}
	return 0;
}
