#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000

struct st{
	int x,y;
}arr[1005];

int visited[1009][1005],vis[1005][1005];
double ans[1009][1009];
int n,m;

double dp(int i,int j)
{
	
	if(i>n or j>m or i<0 or j<0) return inf;
	if(i==n and j==m) return 0;
	
	if(visited[i][j]!=0) return ans[i][j];
	
	double res=inf,res1 = inf,res2 = inf;
	
	if(vis[i+1][j+1]==1)
	{
		res =  dp(i+1,j+1)+(100.0*sqrt(2));
		
	}
	if(vis[i+1][j]==0) res1 = dp(i+1,j)+100.0 ;
	if(vis[i][j+1]==0)res2 = dp(i,j+1)+100.0;
	//vis[i+1][j+1]=0;
	ans[i][j] = min(res1,res2);
	ans[i][j] = min(ans[i][j],res);
	visited[i][j]= 1;
	
	return ans[i][j];
 
}

int main()
{
	int k;
	scanf("%d%d",&n,&m);
	scanf("%d",&k);
	
	memset(visited,0,sizeof(visited));
	memset(vis,0,sizeof(vis));
	
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&arr[i].x,&arr[i].y);
		vis[arr[i].x][arr[i].y]=1;
	}
	
	printf("%.0lf\n",round(dp(0,0)));
	
	
	return 0;
}
