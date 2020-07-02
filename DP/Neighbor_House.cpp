#include <bits/stdc++.h>
using namespace std;

int visited[100][100];

struct st{
	int rgb[4];
}arr[50];

int dp(int n,int color)
{
	if(n<0) return 0;
	if(visited[n][color]!=-1) return visited[n][color];
	int res = 1000000;
	
	for(int i=1;i<=3;i++)
	{
		if(i!=color) res = min(res, dp(n-1,i));
	}
	
	return visited[n][color] = res + arr[n].rgb[color];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t,n,ans,a,b,c;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		memset(visited,-1,sizeof(visited));
		//memset(&arr,0,sizeof(st));  //struct array reset hobe...
		//delete[] arr;     //struct array er sob element delete hobe...
		
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&arr[i].rgb[1],&arr[i].rgb[2],&arr[i].rgb[3]);
		}
		//int color = 1;
		//printf("%d\n",arr[0].rgb[color]);

		a = dp(n-1,1);
		b = dp(n-1,2);
		c = dp(n-1,3);
		
		ans = min(a,b);
		ans = min(ans,c);
		
		printf("Case %d: %d\n",k,ans);
	}
	
	return 0;
}
