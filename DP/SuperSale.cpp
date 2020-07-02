#include <bits/stdc++.h>
using namespace std;

int n,p[10005],w[10005],visited[1000][1000];

int dp(int weight,int n)
{
	if(n==0 or weight==0) return 0;
	if(visited[weight][n]!=0) return visited[weight][n];
	
	if(w[n-1]>weight)
	{
		visited[weight][n] = dp(weight,n-1);
	}
	else 
	{
		visited[weight][n] = max(p[n-1] + dp(weight-w[n-1],n-1),dp(weight,n-1));
	}
	return visited[weight][n];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,q,m;
	scanf("%d",&t);
	while(t--)
	{
		memset(visited,0,sizeof(visited));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&p[i],&w[i]);
		}
		
		scanf("%d",&q);
		int ans = 0;
		for(int i=0;i<q;i++)
		{
			scanf("%d",&m);
			ans+=dp(m,n);
		}
		printf("%d\n",ans);	
	}
	
	return 0;
}
