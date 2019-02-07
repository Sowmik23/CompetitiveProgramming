#include <bits/stdc++.h>
using namespace std;

int n,src;
int arr[10000][10000],visited[10000][10000];

int dp(int i, int msk)
{	
	if(msk==(1<<n)-1) return arr[i][src];
	if(visited[i][msk]!=-1) return visited[i][msk];
	for(int j=0;j<n;j++)
	{
		if(i==j or msk&(1<<j)) continue;
		visited[i][msk] = min(visited[i][msk],dp(j,msk|(1<<j)) + arr[i][j]);
	}
	return visited[i][msk];
}

int main()
{
	scanf("%d%d",&n,&src);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	memset(visited,-1,sizeof(visited));
	
	cout<<dp(src,(1<<src))<<endl;
	
	return 0;
}
