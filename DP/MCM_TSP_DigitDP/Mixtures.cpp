#include <bits/stdc++.h>
using namespace std;

#define mx 1e9

int arr[1000],visited[109][109];

int sum(int a,int b)
{
	int res=0;
	for(int i=a;i<=b;i++)
	{
		res+=arr[i];
		res=res%100;
	}
	return res;
}

int dp(int i,int j)
{
	if(i==j) return 0;
	if(visited[i][j]!=-1) return visited[i][j];
	
	visited[i][j] = mx;
	
	for(int k=i;k<j;k++)
	{
		visited[i][j] = min(visited[i][j], (dp(i,k)+dp(k+1,j) + sum(i,k)*sum(k+1,j)) );
	}
	return visited[i][j];
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		memset(visited,-1,sizeof(visited));
		
		printf("%d\n",dp(0,n-1));
	}
	
	return 0;
}
