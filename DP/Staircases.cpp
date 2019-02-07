#include <bits/stdc++.h>
using namespace std;

long long visited[505][505];

long long dp(int n,int m)
{
	if(n==0) return 1;
	if(m==0) return 0;
	
	if(visited[n][m]==-1)
	{
		if(n>=m) visited[n][m] = dp(n-m,m-1) + dp(n,m-1);
		else visited[n][m] = dp(n,m-1);
	}
	return visited[n][m];
}

int main()
{
	int n;
	long long ans;
	memset(visited,-1,sizeof(visited));
	scanf("%d",&n);
	ans = dp(n,n-1);
	printf("%lld\n",ans);
	
	return 0;
}
